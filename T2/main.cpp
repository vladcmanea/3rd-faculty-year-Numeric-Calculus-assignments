#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>

#define INFILE "input.txt"
#define OUTFILE "output.txt"

using namespace std;

int N;
double **A, *D, *B, *X, *Y;
double E;

double* computeXinferior(double** A, double* B)
{
	if (!A) 
		throw "computeXinferior: invalid A";

	if (!B) 
		throw "computeXinferior: invalid B";

	int N = A[0][0];
	double *X;

	if (!(X = (double*)malloc((N + 1) * sizeof(double))))
		throw "computeXinferior: insufficient memory space";

	X[0] = N;

	for (int i = 1; X && i <= N; ++i)
	{
		X[i] = B[i];
		
		for (int j = 1; j < i; ++j)
			X[i] -= A[i][j] * X[j];
		
		if (fabs(A[i][i]) <= E)
			throw "computeXinferior: division by 0";

		X[i] /= A[i][i];
	}

	return X;
}

double* computeXsuperior(double **A, double *B)
{
	if (!A) 
		throw "computeXsuperior: invalid A";

	if (!B) 
		throw "computeXinferior: invalid B";

	int N = A[0][0];
	double *X;

	if (!(X = (double*)malloc((N + 1) * sizeof(double))))
		throw "computeXinferior: insufficient memory space";

	X[0] = N;

	for (int i = N; X && i >= 1; --i)
	{
		X[i] = B[i];
	
		for (int j = N; j > i; --j)
			X[i] -= A[j][i] * X[j];
		
		if (fabs(A[i][i]) <= E)
			throw "computeXinferior: division by 0";

		X[i] /= A[i][i];
	}

	return X;
}

void computeL(double **A, double *D)
{
	if (!A) 
		throw "computeL: invalid A";

	if (!D)
		throw "computeL: invalid D";

	int N = A[0][0];

	for (int p = 1; p <= N; ++p)
	{
		double S = 0;
	
		for (int j = 1; j < p; ++j)
			S += A[p][j] * A[p][j];

		A[p][p] = sqrt(A[p][p] - S);

		if (fabs(A[p][p]) <= E)
			throw "computeL: division by 0";
		
		for (int i = p + 1; i <= N; ++i)
		{
			for (int j = 1; j < p; ++j)
				A[i][p] -= A[i][j] * A[p][j];

			A[i][p] /= A[p][p];
		}
	}
}

double euclideanNorm(double *V)
{
	if (!V)
		throw "euclideanNorm: invalid V";

	int N = V[0];
	double S = 0;

	for (int i = 1; i <= N; ++i)
		S += V[i] * V[i];

	return sqrt(S);
}

double determinantTriangular(double **A)
{
	if (!A) 
		throw "determinantTriangular: invalid A";

	int N = A[0][0];
	double D = 1;

	for (int i = 1; i <= N; ++i)
		D *= A[i][i];

	return D;
}

void reconstructA(double **A, double *D)
{
	if (!A) 
		throw "reconstructA: invalid A";

	if (!D)
		throw "reconstructA: invalid D";

	int N = A[0][0];
	
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			A[j][i] = A[i][j];

	for (int i = 1; i <= N; i++)
		A[i][i] = D[i];
}

double* multiplySquareWithLine(double **A, double *X)
{
	if (!A) 
		throw "multiplySquareWithLine: invalid A";

	if (!X) 
		throw "multiplySquareWithLine: invalid X";

	int N = A[0][0];
	double *Y;

	if (!(Y = (double*)malloc((N + 1) * sizeof(double))))
		throw "multiplySquareWithLine: insufficient memory space";

	Y[0] = N;

	for (int i = 1; i <= N; i++)
	{
		Y[i] = 0;
		for (int j = 1; j <= N; j++)
			Y[i] += A[i][j] * X[j];
	}

	return Y;
}

double* subtractLineFromLine(double *X, double *Y)
{
	if (!X) 
		throw "subtractSquareFromSquare: invalid X";

	if (!Y) 
		throw "subtractSquareFromSquare: invalid Y";

	int N = A[0][0];
	double *Z;

	if (!(Z = (double*)malloc((N + 1) * sizeof(double))))
		throw "subtractSquareFromSquare: insufficient memory space";

	Z[0] = N;

	for (int i = 1; i <= N; i++)
		Z[i] = X[i] - Y[i];

	return Z;
}

int main()
{
	// set files
	freopen(INFILE, "r", stdin);
	freopen(OUTFILE, "w", stdout);

	// read N
	printf("Please provide the matrix dimension N: ");
	scanf("%d", &N);

	// read E
	printf("Please provide the calculus precision E: ");
	scanf("%lf", &E);

	// allocate matrix A
	if (!(A = (double**)malloc((N + 1) * sizeof(double*))))
		throw "main: insufficient memory space";

	// allocate array A[0]
	if (!(A[0] = (double*)malloc(sizeof(double))))
		throw "main: insufficient memory space";

	// allocate arrays A[1], ..., A[N]
	for (int i = 1; i <= N; ++i)
		if (!(A[i] = (double*)malloc((N + 1) * sizeof(double))))
			throw "main: insufficient memory space";

	// allocate array D
	if (!(D = (double*)malloc((N + 1) * sizeof(double))))
		throw "main: insufficient memory space";

	// set the size of matrix A
	A[0][0] = N;
	printf("Please write the %d x %d elements of matrix A:\n", N, N);
	
	// read matrix A
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			scanf("%lf", &A[i][j]);

	// test if A is symmetric
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			if (A[i][j] != A[j][i])
				throw "main: A is not symmetric";

	// copy diagonal of A in D
	for (int i = 0; i <= N; ++i)
		D[i] = A[i][i];

	// compute the matrix L
	computeL(A, D);

	// test if L has positive diagonal elements
	for (int i = 1; i <= N; ++i)
		if (!(A[i][i] >= E))
			throw "main: L does not have positive diagonal elements";

	// print the determinant of A
	printf("The determinant of A is: %.16lf\n", pow(determinantTriangular(A), 2));

	// test if A has positive determinant
	if (!(pow(determinantTriangular(A), 2) >= E))
		throw "main: the determinant of A is 0";

	// allocate array B
	if (!(B = (double*)malloc((N + 1) * sizeof(double))))
		throw "main: insufficient memory space";

	// set the size of array B
	B[0] = N;
	printf("Please write the %d elements of array B:\n", N);
	
	// read array B
	for (int i = 1; i <= N; ++i)
		scanf("%lf", &B[i]);

	// compute L * y = B
	Y = computeXinferior(A, B);
	
	// compute L ^ T * x = y
	X = computeXsuperior(A, Y);

	// write solution array X
	printf("The solution array X is:\n");
	for (int i = 1; i <= N; ++i)
		printf("%.16lf ", X[i]);
	printf("\n");

	// reconstruct A
	reconstructA(A, D);

	// compute the Euclidean norm of the difference
	double R = euclideanNorm(subtractLineFromLine(multiplySquareWithLine(A, X), B));

	// write correctness
	if (fabs(R) <= E)
		printf("The vector X is correct\n");
	else
		printf("The vector X is incorrect");

	// free arrays A[0], ..., A[N]
	for (int i = 0; i <= N; ++i)
		free(A[i]);
	
	// free all dynamic data structures
	free(A);
	free(D);
	free(B);

	// done :)
	return 0;
}
