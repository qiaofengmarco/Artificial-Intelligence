#include "Headers.h"
#include "QS.hpp"

int main()
{
    QS solver(1000000);
    vector<int> solution;
    solver.solve(solution);
    Solver::printSolution(solution);
    cout << "Successful." << endl;
    system("pause");
    return 0;
}