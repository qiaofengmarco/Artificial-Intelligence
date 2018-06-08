#include "Headers.h"
#include "Population.hpp"

int main()
{
    Population population(50, 0, 9);
    //population.printIndividuals();
    double max = 0, ans = 0;
    while (max < 24.8553)
    {
        population.evolve(0.3, max, ans);
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