#ifndef QS_SOLVER_HPP
#define QS_SOLVER_HPP

#include "Headers.h"
#include "Solver.hpp"

class QS: public Solver
{
private: 
    long long rand_seed = (long long) time(0);
    int c = 90;
    int my_rand(int max)
    {
        double i;

        rand_seed *= ((long long) 134775);
        rand_seed += 127;
        rand_seed %= RAND_MAX;
        rand_seed++;

        i = ((double) rand_seed) / (double) RAND_MAX;

        return (int) (max * i);
    }
    bool try_swap(vector<int> &solution, int i, int j, int* ld, int* rd, int& sum_ld, int& sum_rd)
    {

        int ld_change = 0, rd_change = 0;
        
        if (--ld[problem_size - 1 + solution[i] - i] >= 1) ld_change++;
        if (--ld[problem_size - 1 + solution[j] - j] >= 1) ld_change++;
        if (--rd[solution[i] + i] >= 1) rd_change++;
        if (--rd[solution[j] + j] >= 1) rd_change++;
        
        if ((solution[i] - i == solution[j] - j) && (!ld[problem_size - 1 + solution[i] - i])) ld_change--;
        if ((solution[i] + i == solution[j] + j) && (!rd[solution[i] + i])) rd_change--;
        
        if (ld[problem_size - 1 + solution[j] - i] >= 1) ld_change--;
        if (ld[problem_size - 1 + solution[i] - j] >= 1) ld_change--;
        if (rd[solution[j] + i] >= 1) rd_change--;
        if (rd[solution[i] + j] >= 1) rd_change--;

        if ((solution[i] - j == solution[j] - i) && (!ld[problem_size - 1 + solution[j] - i])) ld_change--;
        if ((solution[i] + j == solution[j] + i) && (!rd[solution[i] + j])) rd_change--;
            
        

        if ((ld_change > 0) || (rd_change > 0))
        {
            ld[problem_size - 1 + solution[j] - i]++;
            ld[problem_size - 1 + solution[i] - j]++;
            rd[solution[j] + i]++;
            rd[solution[i] + j]++;

            swap(solution[i], solution[j]);
            sum_ld -= ld_change;
            sum_rd -= rd_change;
            return true;
        }
        else
        {
            ld[problem_size - 1 + solution[i] - i]++;
            ld[problem_size - 1 + solution[j] - j]++;
            rd[solution[i] + i]++;
            rd[solution[j] + j]++;
        }
        return false;
    }
    void random(vector<int> &solution, int* ld, int* rd)
    {
        int next;
        memset(ld, 0, sizeof(int) * 2 * problem_size);
        memset(rd, 0, sizeof(int) * 2 * problem_size);
        for (int i = 0; i < problem_size; i++)
            solution[i] = i;
        for (int i = 0; i < problem_size - c; i++)
        {
            do
            {
                next = i - 1 + my_rand(problem_size - i);
            } while ((rd[solution[next] + i] >= 1) || (ld[problem_size - 1 + solution[next] - i] >= 1));
            swap(solution[i], solution[next]);
            ld[problem_size - 1 + solution[i] - i]++;
            rd[solution[i] + i]++;
        }
        for (int i = problem_size - c; i < problem_size; i++)
        {
            next = i - 1 + my_rand(problem_size - i);
            swap(solution[i], solution[next]);
            ld[problem_size - 1 + solution[i] - i]++;
            rd[solution[i] + i]++;
        }
    }   
    void calc_conflict(int* ld, int* rd, int &sum_ld, int &sum_rd)
    {
        sum_ld = 0;
        sum_rd = 0;
        for (int i = 0; i < 2 * problem_size; i++)
        {
            if (ld[i] > 0)
                sum_ld += ld[i] - 1;
            if (rd[i] > 0)
                sum_rd += rd[i] - 1;
        }
    }
public:
    QS(int ps): Solver(ps) 
    {
        
    }
    void solve(vector<int> &solution)
    {
        solution.resize(problem_size);
        int *ld, *rd, sum_ld, sum_rd, loop_time, swap_count;
        ld = (int*) malloc(2 * problem_size * sizeof(int));
        rd = (int*) malloc(2 * problem_size * sizeof(int));

        random(solution, ld, rd);
        calc_conflict(ld, rd, sum_ld, sum_rd);
        loop_time = 0;
        swap_count = 0;

        int row, col, count = 0, i = problem_size - c;
        bool flag, flag1;
        do
        {
            cout << "Looping" << endl;
            while ((sum_ld > 0) || (sum_rd > 0))
            {
                flag1 = false;
                for (; i < problem_size; i++)
                {
                    flag = false;
                    if ((ld[problem_size - 1 + solution[i] - i] == 1) && (rd[solution[i] + i] == 1)) continue;
                    row = my_rand(problem_size - 1);
                    for (; row < problem_size; row++)
                    {
                        if (row == i) continue;
                        col = solution[row];
                        if ((ld[problem_size - 1 + col - row] == 1) && (rd[col + row] == 1)) continue;
                        flag = try_swap(solution, i, row, ld, rd, sum_ld, sum_rd);
                        if (flag)
                        {
                            flag1 = true;
                            swap_count++;
                            break;
                        }
                    }
                }
                i = 0;
                if (!flag1)
                    break;
            }
            calc_conflict(ld, rd, sum_ld, sum_rd);
            cout << sum_ld << " " << sum_rd << endl;
            if ((sum_ld == 0) && (sum_rd == 0))
            {
                cout << "A solution is found." << endl;
                cout << "Number of re-initialization: " << loop_time << endl;
                cout << "Number of swapping queens from this initial configuration: " << swap_count << endl;
                break;
            }
            random(solution, ld, rd);
            calc_conflict(ld, rd, sum_ld, sum_rd);
            swap_count = 0;
            loop_time++;
        }
        while (true);
        free(ld);
        free(rd);
        ld = NULL;
        rd = NULL; 
    }
};

#endif