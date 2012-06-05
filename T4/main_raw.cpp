#include <cstdio>
#include <vector>
#include <hash_map>

#define EPS 1e-10
#define KMAX 100
#define DIVERG 100000000ll

#define INFILE0 "mr0.txt"
#define OUTFILE0 "rez00.txt"

#define INFILE1 "mr1.txt"
#define OUTFILE1 "rez10.txt"

#define INFILE2 "mr2.txt"
#define OUTFILE2 "rez20.txt"

#define INFILE3 "mr3.txt"
#define OUTFILE3 "rez30.txt"

using namespace std;

int N;
double Dx;

vector<double> b;
vector<double> X;

vector<double> diagonal;
vector<double> values;
vector<int> columns;
vector<int> lines;

char S[32], *T;
char F[] = {' ', ',', '\0'};

vector<double> multiplySquareWithLine(vector<double> _diagonal, 
	vector<double> _values, vector<int> _columns, 
	vector<int> _lines, vector<double> _X)
{
	vector<double> Y;

	for (int i = 0; i < _X.size(); ++i)
	{
		Y.push_back(_diagonal[i] * _X[i]);

		for (int j = _lines[i]; j < _lines[i + 1]; ++j)
			Y[i] += _values[j] * _X[_columns[j]];
	}

	return Y;
}

vector<double> subtractLineFromLine(vector<double> _X, vector<double> _Y)
{
	if (_X.size() != _Y.size())
		throw "subtractLineFromLine: could not match vector lengths";

	vector<double> Z;

	for (int i = 0; i < _X.size(); ++i)
		Z.push_back(_X[i] - _Y[i]);

	return Z;
}

double norm1(vector<double> _X)
{
	double S = 0;

	for (int i = 0; i < _X.size(); ++i)
		S += abs(_X[i]);

	return S;
}

void read(char *_infile)
{
	double v;
	int k, j, c = 0, NN = 0;
	vector<int> count;
	FILE *fin = fopen(_infile, "r");
	fscanf(fin, "%d", &N); 
	
	b.clear();
	diagonal.clear();
	lines.clear();
	columns.clear();
	values.clear();

	for (int i = 0; i < N; ++i) 
	{
		fscanf(fin, "%lf", &v);
		b.push_back(v);
		count.push_back(0);
		diagonal.push_back(0);
	}

	while (fscanf(fin, "%lf , %d, %d", &v, &k, &j) == 3)
		if (--k != --j)
		{
			++count[k];
			++NN;
		}

	lines.push_back(0);
	count[N - 1] = 0;

	for (int i = 1; i < N; ++i)
	{
		lines.push_back(lines[i - 1] + count[i - 1]);
		count[i - 1] = 0;
	}

	lines.push_back(NN);
	fseek(fin, 0, SEEK_SET);
	fscanf(fin, "%d", &N); 

	for (int i = 0; i < N; ++i) 
		fscanf(fin, "%lf", &v);

	for (int i = 0; i < NN; ++i)
	{
		values.push_back(0);
		columns.push_back(0);
	}

	while (fscanf(fin, "%lf , %d, %d", &v, &k, &j) == 3 && c <= N)
	{
		k--;
		j--;

		if (k == j)
		{
			if (-EPS < v && v < EPS)
				c = N + 1;
			else
				++c;

			diagonal[k] = v;
		}
		else
		{
			values[lines[k] + count[k]] = v;
			columns[lines[k] + count[k]] = j; 
			++count[k];
		}
	}

	fclose(fin);

	if (c != N)
		throw "solve: matrix has a zero element on diagonal";
}

void solve()
{
	// initialize vectors
	X.clear();

	// clear arrays
	for (int i = 0; i < N; ++i)
		X.push_back(0.0); 

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

			for (int j = lines[i]; j < lines[i + 1]; ++j)
				X[i] += values[j] * X[columns[j]];

			X[i] = (b[i] - X[i]) / diagonal[i];
			Dx += abs(X[i] - before);
		}

		++k;
		printf("Iteration %d out of %d\n", k, KMAX);
	}
	while(Dx >= EPS && k <= KMAX && Dx <= DIVERG);
}

void write(char *_outfile)
{
	FILE *fout = fopen(_outfile, "w");

	for (int i = 0; i < N; ++i)
	{
		double S = diagonal[i];
		
		for (int j = lines[i]; j < lines[i + 1] && S >= -EPS; ++j)
			S -= values[j];
		
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
			fprintf(fout, "%.16lf ", X[i]);

		fprintf(fout, "\n");
		fprintf(fout, "Norm:\n");
		fprintf(fout, "%.32lf\n", 
			norm1(subtractLineFromLine(multiplySquareWithLine(diagonal, values, columns, lines, X), b)));
	}
	else
		fprintf(fout, "Diverges\n");

	fclose(fout);
}

void process(char *_infile, char *_outfile)
{
	read(_infile);
	solve();
	write(_outfile);
}

int main()
{
	process(INFILE0, OUTFILE0);
	process(INFILE1, OUTFILE1);
	process(INFILE2, OUTFILE2);
	process(INFILE3, OUTFILE3);

	return 0;
}