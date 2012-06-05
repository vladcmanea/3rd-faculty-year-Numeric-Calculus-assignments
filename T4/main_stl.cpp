#include <cstdio>
#include <vector>
#include <hash_map>

#define EPS 1e-10
#define KMAX 100
#define DIVERG 100000000ll

#define INFILE0 "mr0.txt"
#define OUTFILE0 "rez0.txt"

#define INFILE1 "mr1.txt"
#define OUTFILE1 "rez1.txt"

#define INFILE2 "mr2.txt"
#define OUTFILE2 "rez2.txt"

#define INFILE3 "mr3.txt"
#define OUTFILE3 "rez3.txt"

using namespace std;

int N;
double Dx;
vector<double> b;
vector<double> d;
vector<double> X;
hash_map<int, vector<pair<int, double>>> A;
char S[32], *T;
char F[] = {' ', ',', '\0'};

vector<double> multiplySquareWithLine(hash_map<int, vector<pair<int, double>>> A, vector<double> X)
{
	vector<double> Y;

	for (int i = 0; i < X.size(); ++i)
	{
		Y.push_back(d[i] * X[i]);

		for (int j = 0; j < A[i].size(); ++j)
		{
			Y[i] += A[i][j].second * X[A[i][j].first];
		}
	}

	return Y;
}

vector<double> subtractLineFromLine(vector<double> X, vector<double> Y)
{
	if (X.size() != Y.size())
	{
		throw "subtractLineFromLine: could not match vector lengths";
	}

	vector<double> Z;

	for (int i = 0; i < X.size(); ++i)
	{
		Z.push_back(X[i] - Y[i]);
	}

	return Z;
}

double norm1(vector<double> X)
{
	double S = 0;

	for (int i = 0; i < X.size(); ++i)
	{
		S += abs(X[i]);
	}

	return S;
}

void read(char *infile)
{
	double v;
	int k, j, c = 0;
	FILE *fin = fopen(infile, "r");
	fscanf(fin, "%d", &N); 

	d.clear();
	for (int i = 0; i < N; ++i)
	{
		d.push_back(0);
	}

	for (int i = 0; i < N; ++i) 
	{
		fscanf(fin, "%lf", &v);
		b.push_back(v);
	}

	while (fscanf(fin, "%lf , %d, %d", &v, &k, &j) == 3 && c <= N)
	{
		k--;
		j--;

		if (k == j)
		{
			if (-EPS < v && v < EPS)
			{
				c = N + 1;
			}
			else
			{
				++c;
			}			

			d[k] = v;
		}
		else
		{
			if (A.find(k) == A.end())
			{
				vector<pair<int, double>> vect;
				vect.push_back(make_pair(j, v));
				A.insert(make_pair(k, vect));
			}
			else
			{
				A[k].push_back(make_pair(j, v));
			}
		}
	}

	fclose(fin);

	if (c != N)
	{
		throw "solve: matrix has a zero element on diagonal";
	}
}

void solve()
{
	// initialize vectors
	X.clear();

	// clear arrays
	for (int i = 0; i < N; ++i)
	{
		X.push_back(0.0); 
	}

	// set initial values
	int k = 0;
	double before;

	do
	{
		Dx = 0;

		for (int i = 0; i < N; ++i)
		{
			before = X[i];
			X[i] = 0;

			for (int j = 0; j < A[i].size(); ++j)
			{
				int first = A[i][j].first;
				double second = A[i][j].second;
				X[i] += second * X[first];
			}

			X[i] = (b[i] - X[i]) / d[i];
			Dx += abs(X[i] - before);
		}

		++k;
		printf("Iteration %d out of %d\n", k, KMAX);
	}
	while(Dx >= EPS && k <= KMAX && Dx <= DIVERG);
}

void write(char *outfile)
{
	FILE *fout = fopen(outfile, "w");

	for (int i = 0; i < N; ++i)
	{
		double S = d[i];
		
		for (int j = 0; j < A[i].size() && S >= -EPS; ++j)
			S -= A[i][j].second;
		
		if (S < -EPS)
		{
			fprintf(fout, "Caution: matrix may not be diagonally dominant\n");
			break;
		}
	}

	if (Dx <= DIVERG)
	{
		fprintf(fout, "Converges:\n");
		
		for (int i = 0; i < N; ++i)
		{
			fprintf(fout, "%.16lf ", X[i]);
		}

		fprintf(fout, "\n");
		fprintf(fout, "Norm:\n");
		fprintf(fout, "%.32lf\n", norm1(subtractLineFromLine(multiplySquareWithLine(A, X), b)));
	}
	else
	{
		fprintf(fout, "Diverges\n");
	}

	fclose(fout);
}

void process(char *infile, char *outfile)
{
	read(infile);
	solve();
	write(outfile);

	A.clear();
	b.clear();
}

int main()
{
	process(INFILE0, OUTFILE0);
	process(INFILE1, OUTFILE1);
	process(INFILE2, OUTFILE2);
	process(INFILE3, OUTFILE3);

	return 0;
}