#include "model.h"

char model::winnerMethod = '_';
bool model::gotMethodSolution = false;

int model::coefNumber = 0;
double model::expoBase = 0;
double model::coef[] = {0};
model * model::instance = 0;
char model::activeFUNCTION = 'p';

QMutex* model::mutex = 0;

double model::newtonSolutionFound = 0;
double model::secantSolutionFound = 0;

model::model()
{
    mutex = new QMutex();
}

model * model::getInstance(){

    if(model::instance == 0)
        model::instance = new model();

    return model::instance;
}



double model::findSquare(const char FUNCTION, const char METHOD, const long KMAX, const double EPS, const bool RAND, const double X0, const double X1, const int RETRYS, const double RATIORETRYS, const double solution){

    /*switch(activeFUNCTION)
    {
    case 'p':
         if(coefNumber <= 1)
           return 0;

    case 'e':
         if(expoBase == 0)
           return 0;
    }*/

    srand((unsigned int)(time(0)));

    double xk_1, xk, x0, x1, delta;
    long k = 0;
    int currentIteration = 0;

    if(RAND == true)
    {
        int r = rand() % 1000;

        x0 = r + solution;

        r = rand() % 100;

        x1 = r - solution;
    }
    else
    {
        x0 = X0;
        x1 = X1;
    }

    // prima iterare nu este vazuta ca fiind un retry
    while(currentIteration <= RETRYS)
    {
        if(METHOD == 'n')
        {
            xk = x0;
            xk_1 = x0;
        }
        else
        {
            xk_1 = x0;
            xk = x1;
        }

        do
        {
            k++;

            delta = deltaF(METHOD, FUNCTION, xk_1, xk, EPS);

            xk_1 = xk;
            xk = xk - delta;

        }while(fabs(delta) >= EPS && k <= KMAX && fabs(delta) <= 100000000);

        // daca am divergenta
        if(fabs(delta) >= EPS){
            currentIteration++;

            x0 = X0 + RATIORETRYS;
            x1 = X1 + RATIORETRYS;
        }
        else break;
    }

    // in xk am memorata solutia cautata
    return xk;
}


double model::deltaF(const char METHOD, const char FUNCTION, const double XK_1, const double XK, double EPS){

    double ans;

    switch(METHOD){
    case 'n':
        {
            double denominator = _F(FUNCTION, XK);

            if(fabs(denominator) <= EPS)
                ans = 0.00001;
            else
                ans = F(FUNCTION, XK) / denominator;

            break;
        }

    case 's':
        {
            double denominator = F(FUNCTION, XK) - F(FUNCTION, XK_1);

            if(fabs(denominator) <= EPS)
                ans = 0.00001;
            else
                ans = ( (XK - XK_1) * F(FUNCTION, XK) ) / denominator;

            break;
        }
    }

    return ans;
}



// functia f
double model::F(const char FUNCTION, const double X)
{
    double ans;

    switch(FUNCTION){
    case 'p':{
               ans = coef[0];

                for(int i = 1; i < coefNumber; i++)
                    ans = coef[i] + ans * X;

                break;
            }

    case 'e':{

                ans = pow(expoBase, X);
                break;
            }

    case 'l':{

                ans = log(X);
                break;
            }

    case 's':{
                ans = sin(X);
                break;
            }

    case 'c':{
                ans = cos(X);
                break;
            }
    }

    return ans;

}

// derivata functiei f
double model::_F(const char FUNCTION, const double X){

    double ans;

    switch(FUNCTION){
    case 'p':{
                double grade = coefNumber - 1;
                ans = coef[0] * grade;

                for(int i = 1; i <= coefNumber - 2; i++)
                    ans = coef[i] * (grade - i) + ans * X;

                break;
            }

    case 'e':{
                ans = pow(expoBase, X) * log(expoBase);
                break;
            }

    case 'l':{

                ans = 1 / X;
                break;
            }

    case 's':{

                ans = cos(X);
                break;
            }

    case 'c':{
                ans = - sin(X);
                break;
            }
    }

    return ans;
}
