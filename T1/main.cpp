#include <cstdio>
#include <cmath>

const double PI = 4 * atan(1.0); 

double Taylor_sin(double x, double e)
{
	while (x > PI) 
		x -= 2 * PI;
	while (x <= -PI) 
		x += 2 * PI;

	double S = 0, Si = x;
	int i = 0;

	while (Si < -e || e < Si)
	{
		S += Si;
		Si = -(x * x) * Si / ((2 * i + 2) * (2 * i + 3));
		++i;
	}

	return S;
}

double Taylor_cos(double x, double e)
{
	while (x > PI) 
		x -= 2 * PI;
	while (x <= -PI) 
		x += 2 * PI;

	double T = 0, Ti = 1;
	int i = 0;

	while (Ti < -e || e < Ti)
	{
		T += Ti;
		Ti = -(x * x) * Ti / ((2 * i + 1) * (2 * i + 2));
		++i;
	}

	return T;
}

int main()
{
	double u = 1, l = 1, x = 1, y, z;
	
	// P1
	int i = 0;
	while (x + u != x) 
	{
		l = u;
		u /= 10;
		++i;
	}
	printf("%.32lf = 10 ^ (-%d)\n", l, i);

	// P2
	y = z = l;
	if ((x + y) + z != x + (y + z)) 
		printf("+c nu este asociativa\n");
	else
		printf("+c este asociativa\n");

	// P3 sin
	x = 7 * PI / 6;
	printf("sin(%.32lf) = %.32lf\n", x, Taylor_sin(x, l * 10));

	// P3 cos
	y = 4 * PI / 3;
	printf("cos(%.32lf) = %.32lf\n", y, Taylor_cos(y, l * 10));

	return 0;
}