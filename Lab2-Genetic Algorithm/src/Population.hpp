#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "Headers.h"
#include "Individual.hpp"

class Population
{
public:
    Population(int sz, int low, int up)
    {
        population_size = sz;
        lower_x = low;
        upper_x = up;
        for (int i = 0; i < sz; i++)
        {
            Individual individual(low, up);
            individual.random();
            individuals.push_back(individual);
        }
        generation = 1;
    }
    double calc_fitness_sum()
    {
        double sum = 0;
        for (int i = 0; i < population_size; i++)
        {
            sum += individuals[i].getFitness();
        }
        fitness_sum = sum;
        return sum;
    }
    int select()
    {
        int index;
        double sum = calc_fitness_sum(), min = individuals[0].getFitness(), temp, slice;
        for (unsigned int i = 1; i < individuals.size(); i++)
        {
            temp = individuals[i].getFitness();
            if (temp < min)
                min = temp;
        } 
        sum -= (min - 1) * individuals.size();
        slice = (double) Individual::myrand(10001) * sum / (double)(10000);
        temp = 0;
        index = 0;
        for (unsigned int i = 0; i < individuals.size(); i++)
        {
            temp = individuals[i].getFitness() - min + 1;
            slice -= temp;
            if (slice <= 0)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    void single_crossover(const Individual &a, const Individual &b, Individual &son, Individual &daugter)
    {
        bitset<BIT_SIZE> temp;
        int cross_place = Individual::myrand(BIT_SIZE - 1);
        for (int i = 0; i < cross_place; i++)
        {
            son.rep[i] = a.rep[i];
            daugter.rep[i] = b.rep[i];
        }
        for (int i = cross_place; i < BIT_SIZE; i++)
        {
            son.rep[i] = b.rep[i];
            daugter.rep[i] = a.rep[i];
        }
        son.this_trans();
        daugter.this_trans();
    }
    void mutate(const Individual &a, Individual &b)
    {
        int k = Individual::myrand(BIT_SIZE);
        b.rep = a.rep;
        b.rep.flip(k);
        b.this_trans();
    }
    void getMax(double &max,  double &ans_x)
    {
        max = individuals[0].getFitness();
        double temp;
        for (int i = 1; i < population_size; i++)
        {
            temp = individuals[i].getFitness();
            if (max < temp)
            {
                ans_x = individuals[i].getX();
                max = temp;
            }
        }
    }
    void evolve(const double mutation_rate, const double cross_rate, double &max, double &ans)
    {
        //mark the availability of an individual
        bool* chosen = (bool*) malloc(sizeof(bool) * population_size);

        memset(chosen, 0, sizeof(bool) * population_size);
        generation++;
        int chosen_count = 0, index1 = 0, index2 = 0, temp = 0, count = 0, cross_count = (int) (population_size * cross_rate);

        Individual son(lower_x, upper_x), daugter(lower_x, upper_x);
        
        //select two individuals in crossover
        do
        {
            if (chosen_count == population_size - 1)
            {
                for (int i = 0; i < population_size; i++)
                    if (!chosen[i])
                    {
                        temp = i;
                        break;
                    }
                mutate(individuals[temp], individuals[temp]);
                chosen_count++;
                break;
            }

            do
            {
                count++;
                index1 = select();
                if (count >= cross_count)
                {
                    for (int j = 0; j < population_size; j++)
                        if (!chosen[j])
                        {
                            index1 = j;
                            break;
                        }
                }
            }
            while (chosen[index1]);

            chosen[index1] = true;
            count = 0;

            do
            {
                count++;
                index2 = select();
                if (count >= cross_count)
                {
                    for (int j = 0; j < population_size; j++)
                        if (!chosen[j])
                        {
                            index2 = j;
                            break;
                        }
                }
            }
            while (chosen[index2]);

            chosen[index2] = true;
            count = 0;
            chosen_count += 2;

            single_crossover(individuals[index1], individuals[index2], son, daugter);
            individuals.push_back(son);
            individuals.push_back(daugter);
        }
        while (chosen_count < cross_count);

        int upper = (int)(population_size * mutation_rate);
        
        //mutation
        for (int i = 0; i < upper; i++)
        {
            Individual son1(lower_x, upper_x);
            temp = Individual::myrand(population_size);
            mutate(individuals[temp], son1);
            individuals.push_back(son1);
        }

        //select and clip
        clip();

        getMax(max, ans);

        free(chosen);
        chosen = NULL;
    }
    void clip()
    {

        bool* chosen = (bool*) malloc(sizeof(bool) * individuals.size());
        memset(chosen, 0, sizeof(bool) * individuals.size());

        sort(individuals.begin(), individuals.end(), comp_individual);
        vector<Individual> new_individuals;
        new_individuals.resize(population_size);
        
        int index = 0;
        unsigned int count = 0;

        for (int i = 0; i < population_size; i++)
        {
            do
            {
                count++;
                index = select();
                if (count >= individuals.size() / 2)
                {
                    for (unsigned int j = 0; j < individuals.size(); j++)
                        if (!chosen[j])
                        {
                            index = j;
                            break;
                        }
                }
            }
            while (chosen[index]);
            chosen[index] = true;
            new_individuals[i] = individuals[index];
            count = 0;
        }
        
        individuals.resize(new_individuals.size());
        individuals.assign(new_individuals.begin(), new_individuals.end());

        vector<Individual>().swap(new_individuals);

        free(chosen);
        chosen = NULL;
    }
    unsigned int getGeneration()
    {
        return generation;
    }
    void printIndividuals()
    {
        char str[10];
        _itoa(generation, str, 10);
        string fname = "./" + string(str) + ".txt";
        ofstream out(fname, ios::out);
        for (int i = 0; i < population_size; i++)
            out << setprecision(6) << individuals[i].getX() << endl;
        out.close();
    }
    ~Population()
    {
        vector<Individual>().swap(individuals);
    }
private:
    int population_size;
    int lower_x, upper_x;
    vector<Individual> individuals;
    unsigned int generation;
    double fitness_sum;
};

#endif