#include "Headers.h"
#include "Population.hpp"

int main()
{
    Population population(80, 0, 9);
    //population.printIndividuals();
    double max = 0, ans = 0;
    int count = 0;
    while ((max < 24.8553) && (count < 300))
    {
        //cout << ++count << endl;
        population.evolve(0.3, 0.6, max, ans);
        //population.printIndividuals();
    }
    cout << "Generation: " << population.getGeneration() << endl;
    cout << "Maximum:" << endl;
    cout << "x = " << setprecision(5) << ans << endl;
    cout << "f(x) = " << setprecision(6) << max << endl;
    cout << endl;
    system("pause");
    return 0;
}