#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "Headers.h"
#include "Board.hpp"

class Node
{
public:
    unsigned int value;
    vector<int> actions;
    Board state;
    Node()
    {
        value = 0;
    }
    Node(const Board &b, int c, const vector<int> &acts)
    {
        state = b; 
        value = c;
        actions.assign(acts.begin(), acts.end());
    }
    Node(const Board &b, int c, const vector<int> &acts, int act)
    {
        state = b;
        value = c;
        actions.assign(acts.begin(), acts.end());
        actions.push_back(act);
    }
    Node(const Board& b, int c)
    {
        state = b;
        value = c;
    }
    Node(int c)
    {
        value = c;
    }
    const Node& operator=(const Node& node)
    {
        state = node.state;
        value = node.value;
        actions.assign(node.actions.begin(), node.actions.end());
        return *this;
    }
};

struct greater_node
{
    bool operator() (const Node &a, const Node &b)
    {
        return a.value > b.value;
    }
};

class Solver
{
public:
    Solver() {}
    Solver(const string &s) 
    {
        name = s;
    }
    virtual bool solve(const Board &stat_board, vector<int> &solution) = 0;
    string getName()
    {
        return name;
    }
    static void print_solution(const Board &start, const vector<int> &solution)
    {
        Board temp(start);
        int tx, ty, tb;
        cout << endl << "Initial State:" << endl;
        temp.draw();
        cout << endl;
        if (solution.size() > 1)
            cout << "There are " << solution.size() << " steps in total in this solution." << endl;
        else
            cout << "There is only one step in total in this solution." << endl;
        for (unsigned int i = 0; i < solution.size(); i++)
        {
            cout << endl;
            cout << "Step " << i + 1 << ": ";
            if (solution[i] == UP)
            {
                tx = temp.position[0].x + direct[UP][0];
                ty = temp.position[0].y + direct[UP][1];
                tb = Board::calc_pos(tx, ty);
                cout << "Move Tile " << temp.board[tb] << " Down." << endl;
                temp.this_move(UP);
                temp.draw();
            }
            else if (solution[i] == DOWN)
            {
                tx = temp.position[0].x + direct[DOWN][0];
                ty = temp.position[0].y + direct[DOWN][1];
                tb = Board::calc_pos(tx, ty);
                cout << "Move Tile " << temp.board[tb] << " Up." << endl;
                temp.this_move(DOWN);
                temp.draw();
            }
            else if (solution[i] == LEFT)
            {
                tx = temp.position[0].x + direct[LEFT][0];
                ty = temp.position[0].y + direct[LEFT][1];
                tb = Board::calc_pos(tx, ty);
                cout << "Move Tile " << temp.board[tb] << " Right." << endl;
                temp.this_move(LEFT);
                temp.draw();
            }
            else
            {
                tx = temp.position[0].x + direct[RIGHT][0];
                ty = temp.position[0].y + direct[RIGHT][1];
                tb = Board::calc_pos(tx, ty);
                cout << "Move Tile " << temp.board[tb] << " Left." << endl;
                temp.this_move(RIGHT);
                temp.draw();
            }
        }
    }
protected: 
    string name;
};

#endif