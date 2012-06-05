#ifndef MODEL_H
#define MODEL_H

#include "time.h"
#include "stdlib.h"
#include "math.h"

#include "QMutex"
// numarul maxim de coeficienti pentru o functie polinomiala
#define NMAX 100


class model
{
private:
    model();
    model(const model &model);
    model operator=(const model &model);

    static model *instance;

public:
    static model * getInstance();

    double findSquare(const char FUNCTION, const char METHOD, const long KMAX, const double EPS, const bool RAND, const double X0, const double X1, const int RETRYS, const double RATIORETRYS, const double solution);

    double deltaF(const char METHOD, const char FUNCTION, const double XK_1, const double XK, double EPS);

    // functia f
    double F(const char FUNCTION, const double X);

    // derivata functiei f
    double _F(const char FUNCTION, const double X);

    // retin datele necesare pentru calcularea functiilor (expo, log)
    static double expoBase;

    // retin datele necesare pentru calcularea functiei polinomiale
    static double coef[NMAX];
    static int coefNumber;

    static char activeFUNCTION, winnerMethod;
    static bool gotMethodSolution;

    static double newtonSolutionFound, secantSolutionFound;

    static QMutex * mutex;
};

#endif // MODEL_H
