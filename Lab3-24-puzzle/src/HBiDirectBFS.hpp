#ifndef HBIDIRECTBFS_HPP
#define HBIDIRECTBFS_HPP

#include "Headers.h"
#include "Board.hpp"
#include "Solver.hpp"

class HBiDirectBFS: public Solver
{
public:
    HBiDirectBFS(string s):Solver(s)
    {

    }
    bool solve(const Board& start_board, vector<int> &solution)
    {
        Node start1(start_board, start_board.Manhattan_Dis), start2(Board::goal_state(), 0), head, tail, child;
        priority_queue< Node, vector<Node>, greater_node > head_frontier;
        queue< Node > tail_frontier;
        head_frontier.push(start1);
        tail_frontier.push(start2);
        unordered_set<Board> head_explored, tail_explored;
        unordered_map<Board, Node > tot;
        unordered_set<Board>::iterator it;
        bool flag;
        while (1)
        {
            if (head_frontier.empty() || tail_frontier.empty()) return false;

            head = head_frontier.top();
            head_frontier.pop();
            it = head_explored.find(head.state);
            if (it != head_explored.end())
                continue;
            head_explored.insert(head.state);
            tot[head.state] = head;
            for (int i = 0; i < 4; i++)
            {
                flag = head.state.movable(i);
                if (!flag) continue;
                child = Node(head.state.move(i), head.value + 1, head.actions, i);
                child.value += child.state.Manhattan_Dis - head.state.Manhattan_Dis;
                it = tail_explored.find(child.state);
                if (it != tail_explored.end())
                {
                    solution.assign(child.actions.begin(), child.actions.end());
                    vector<int> temp_act(tot[child.state].actions);
                    for (int j = temp_act.size() - 1; j >= 0; j--)
                        solution.push_back(reverse_act(temp_act[j]));
                    return true;
                }
                head_frontier.push(child);
            }

            tail = tail_frontier.front();
            tail_frontier.pop();

            it = tail_explored.find(tail.state);
            if (it != tail_explored.end())
                continue;
            tail_explored.insert(tail.state);
            tot[tail.state] = tail;
            for (int i = 0; i < 4; i++)
            {
                flag = tail.state.movable(i);
                if (!flag) continue;
                child = Node(tail.state.move(i), tail.value + 1, tail.actions, i);
                it = head_explored.find(child.state);
                if (it != head_explored.end())
                {
                    solution.assign(tot[child.state].actions.begin(), tot[child.state].actions.end());
                    for (int j = child.actions.size() - 1; j >= 0; j--)
                        solution.push_back(reverse_act(child.actions[j]));
                    return true;
                }
                tail_frontier.push(child);
            }
        }
    }
};

#endif