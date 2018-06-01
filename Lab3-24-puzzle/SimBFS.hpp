#ifndef SIMBFS_HPP
#define SIMBFS_HPP

#include "Headers.h"
#include "Board.hpp"
#include "Solver.hpp"

class SimBFS: public Solver
{
public:
    SimBFS(string str): Solver(str)
    {        
    }
    bool solve(const Board& start_board, vector<int> &solution)
    {
        Node start(start_board, 0), node, child;
        queue<Node> frontier;
        frontier.push(start);
        unordered_set<Board> explored;
        unordered_set<Board>::iterator it;
        bool flag;
        while (1)
        {
            if (frontier.empty()) return false;
            node = frontier.front();
            frontier.pop();
            for (int i = 0; i < 4; i++)
            {
                flag = node.state.movable(i);
                if (!flag) continue;
                child = Node(node.state.move(i), node.value + 1, node.actions, i);
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