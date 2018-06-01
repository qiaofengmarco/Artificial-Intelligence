#ifndef SIMBIDIRECTBFS_HPP
#define SIMBIDIRECTBFS_HPP

#include "Headers.h"
#include "Board.hpp"
#include "Solver.hpp"

class SimBiDirectBFS: public Solver
{
public:
    SimBiDirectBFS(string s):Solver(s)
    {

    }
    bool solve(const Board& start_board, vector<int> &solution)
    {
        Node start1(start_board, 0), start2(Board::goal_state(), 0), head, tail, child;
        queue< Node > head_frontier;
        queue< Node > tail_frontier;
        head_frontier.push(start1);
        tail_frontier.push(start2);
        unordered_set<Board> head_explored, tail_explored;
        unordered_map<Board, Node > tot;
        unordered_set<Board>::iterator it;
        bool flag;
        while (1)
        {
            //if both frontiers are empty, then there are no solutions for sure.
            if (head_frontier.empty() || tail_frontier.empty()) return false;
            
            //head = the first element of the forward search's frontier
            head = head_frontier.front();
            head_frontier.pop();

            it = head_explored.find(head.state);
            //if head is explored, then we should choose another node as head            
            if (it != head_explored.end()) continue;

            head_explored.insert(head.state);
            tot[head.state] = head;

            //for four directions
            for (int i = 0; i < 4; i++)
            {
                flag = head.state.movable(i);
                if (!flag) continue; //if the current action is not a legal action, choose another one 
                child = Node(head.state.move(i), head.value + 1, head.actions, i);
                it = tail_explored.find(child.state);
                if (it != tail_explored.end()) //if the current child is explored in backward search's frontier
                {
                    //OK, we find a solution
                    solution.assign(child.actions.begin(), child.actions.end());
                    vector<int> temp_act(tot[child.state].actions);
                    for (int j = temp_act.size() - 1; j >= 0; j--)
                        solution.push_back(reverse_act(temp_act[j]));
                    return true;
                }
                head_frontier.push(child);
            }

            //tail = the first element of the backward search's frontier
            tail = tail_frontier.front();
            tail_frontier.pop();

            it = tail_explored.find(tail.state);
            //if tail is explored, then we should choose another node as tail 
            if (it != tail_explored.end()) continue;
            tail_explored.insert(tail.state);
            tot[tail.state] = tail;
            for (int i = 0; i < 4; i++)
            {
                flag = tail.state.movable(i);
                if (!flag) continue; //if the current action is not a legal action, choose another one 
                child = Node(tail.state.move(i), tail.value + 1, tail.actions, i);
                it = head_explored.find(child.state);
                if (it != head_explored.end()) //if the current child is explored in forward search's frontier
                {
                    //OK, we find a solution
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