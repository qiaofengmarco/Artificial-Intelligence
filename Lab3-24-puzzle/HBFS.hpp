#ifndef MY_HBFS_HPP
#define MY_HBFS_HPP

#include "Headers.h"
#include "Board.hpp"
#include "Solver.hpp"


class HBFS: public Solver
{
public:
    HBFS(string str): Solver(str)
    {

    }
    bool solve(const Board& start_board, vector<int> &solution)
    {
        Node start(start_board, start_board.Manhattan_Dis), node, child;
        priority_queue<Node, vector<Node>, greater_node> frontier;
        frontier.push(start);
        unordered_set<Board> explored;
        unordered_set<Board>::iterator it;
        bool flag;
        while (1)
        {
            if (frontier.empty()) return false;
            node = frontier.top();
            frontier.pop();
            for (int i = 0; i < 4; i++)
            {
                flag = node.state.movable(i);
                if (!flag) continue;
                child = Node(node.state.move(i), node.value + 1, node.actions, i);
                child.value += child.state.Manhattan_Dis - node.state.Manhattan_Dis;
                it = explored.find(child.state);
                if (it == explored.end())
                {
                    if (Board::goal_test(child.state))
                    {
                        solution.assign(child.actions.begin(), child.actions.end());
                        return true;
                    }
                    frontier.push(child);
                }
            }
        }
    }
};

#endif