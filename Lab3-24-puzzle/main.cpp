#include "Headers.h"
#include "Board.hpp"
#include "SimBFS.hpp"
#include "HBiDirectBFS.hpp"
#include "SimBiDirectBFS.hpp"
#include "HBFS.hpp"

int main()
{
    SimBFS SimBFS("Simple Breadth-first Search");
    SimBiDirectBFS SimBiBFS("Simple Bidirectional Breadth-first Search");
    HBiDirectBFS HBiBFS("Bidirectional Best-first Search");
    HBFS HBFS("Best-first Search based on Priority Queue");
    Board::puzzle = 24;
    Board::grid_size = 5;
    vector<int> solution;
    int flash_back = 10;
    Board start;
    string s;
    char* str = new char[2];
    //for (int i = 0; i < 30; i++)
    //{
    //    srand((unsigned int) (time(0) * i) % 12345);
    //    start.random(flash_back);
    //    _itoa(i, str, 10);
    //    s = "./board10" + string(str);
    //    start.writeBoard(s + ".txt");
    //    Sleep(1000);
    //}
    //int solution_count = 0;
    //bool Fail = false;
    //cout << "Problem Solver: " << HBiBFS.getName() << endl;
    //DWORD start_c = GetTickCount();
    //for (int i = 0; i < 30; i++)
    //{
    //    _itoa(i, str, 10);
    //    s = "./board" + string(str);
    //    start.readBoard(s + ".txt");
    //    //start.draw();
    //    HBiBFS.solve(start, solution);
    //    if (solution.size() == 0)
    //    {
    //        Fail = true;
    //        break;
    //    }
    //    //Solver::print_solution(start, solution);
    //    solution_count += solution.size();
    //}
    //if (Fail)
    //{
    //    cout << "Fail!" << endl;
    //}
    //else
    //{
    //    DWORD stop_c = GetTickCount();
    //    cout << "Total running time: " << (double) ((double) (stop_c - start_c) * 1.0 / 1000) << "s" << endl;
    //    cout << "Averaged number of steps in solutions: " << (double)((double)(solution_count) / 30.0) << endl;
    //}
    system("pause");
    return 0;
}