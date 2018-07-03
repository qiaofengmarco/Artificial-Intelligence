#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP

#include "Headers.h"

#define BIT_SIZE 30

class Individual
{
public:
    bitset<BIT_SIZE> rep;
    Individual(){}
    Individual(double lx, double ux)
    {
        upper_x = ux;
        lower_x = lx;
    }
    Individual(const Individual& a)
    {
        rep = a.rep;
        x = a.x;
        fitness = a.fitness;
        upper_x = a.upper_x;
        lower_x = a.lower_x;
    }
    int size()
    {
        return BIT_SIZE;
    }
    void random()
    {
        for (int i = 0; i < BIT_SIZE; i++)
           rep[i] = (bool)(myrand(2));
        this_trans();
    }
    void this_trans()
    {
        double ans = 0, temp = 1.0;
        for (int i = 0; i < BIT_SIZE; i++)
        {
            ans += rep[i] * temp;
            temp *= 2;
        }
        x = (upper_x - lower_x) * ans / (temp - 1.0);
        calc(x);
    }
    double getFitness()
    {
        return fitness;
    }
    double getFitness() const 
    {
        return fitness;
    }
    template<size_t SIZE>
    static double trans(bitset<SIZE> bit)
    {
        double ans = 0, temp = 1.0;
        for (int i = 0; i < SIZE; i++)
        {
            ans += rep[i] * temp;
            temp *= 2;
        }
        ans = (upper_x - lower_x) * ans / (temp - 1.0);
        return ans;
    }
    double getX()
    {
        return x;
    }
    double getX() const
    {
        return x;
    }
    void setX(double x1)
    {
        x = x1;
        calc(x);
    }
    static int myrand(int max)
    {
        double i;

        seed *= ((long long) 134775);
        seed += 131;
        seed %= RAND_MAX;
        seed++;

        i = ((double) seed) / (double) RAND_MAX;

        return (int) (max * i);
    }
    Individual operator=(const Individual& a)
    {
        rep = a.rep;
        x = a.x;
        fitness = a.fitness;
        upper_x = a.upper_x;
        lower_x = a.lower_x;
        return (*this);
    }
    ~Individual()
    {
    }
    static long long seed;
private:
    double fitness, x, upper_x, lower_x;
    void calc(double x)
    {
        fitness = x + 10 * sin(5 * x) + 7 * cos(4 * x);
    }
};

long long Individual::seed = (long long) time(0);

bool comp_individual(const Individual& a, const Individual& b)
{
    return a.getFitness() > b.getFitness();
}

#endif