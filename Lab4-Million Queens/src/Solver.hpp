#ifndef MY_SOLVER_HPP
#define MY_SOLVER_HPP

#include "Headers.h"

class Solver
{
public:
    Solver(int ps) 
    {
        problem_size = ps;
    };
    virtual void solve(vector<int> &solution) = 0;
    void static record(const vector<int> &queens)
    {
        ofstream out("./Solution_plain.txt");
        out << queens.size();
        for (unsigned int i = 0; i < queens.size(); i++)
            out << queens[i];
        out.close();
    }
    void static getRecord(vector<int> &queens, int &problem_size)
    {
        ifstream in("./Solution_plain.txt");
        in >> problem_size;
        queens.resize(problem_size);
        for (int i = 0; i < problem_size; i++)
            in >> queens[i];
        in.close();
    }
    void static printSolution(const vector<int> &queens)
    {
        ofstream out("./Solution.txt");
        for (unsigned int i = 0; i < queens.size(); i++)
            out << "Queen at Row " << i + 1 << " is placed at Column " << queens[i] + 1 << "." << endl;
        cout << "Finished printing the solution." << endl;
        out.close();
    }
protected:
    int problem_size = 8;
};

#endif