package cn5;

public class Numeric {

    public static double Norm1Line(double V[]) throws Exception {
        if (V == null) {
            throw new Exception("Norm1Line: invalid V");
        }

        int N = V.length;
        double S = 0;

        for (int i = 0; i < N; ++i) {
            S += Math.abs(V[i]);
        }

        return S;
    }

    // maximul in valoarea absoluta
    public static double NormInfLine(double V[]) throws Exception {
        if (V == null) {
            throw new Exception("Norm1Line: invalid V");
        }

        int N = V.length;
        double S = 0;

        for (int i = 0; i < N; ++i) {
            if (Math.abs(V[i]) >= S) {
                S = Math.abs(V[i]);
            }
        }

        return S;
    }

    // suma elementelor (in valoare absoluta)
    public static double Norm1Square(double V[][]) throws Exception {
        if (V == null) {
            throw new Exception("Norm1Square: invalid V");
        }

        for (int i = 0; i < V.length; ++i) {
            if (V[i].length != V.length) {
                throw new Exception("Norm1Square: invalid sizes");
            }
        }

        int N = V.length;
        double max = Double.MIN_VALUE;

        for (int i = 0; i < N; ++i) {
            double sum = 0;
            for (int j = 0; j < N; ++j) {
                sum += V[i][j];
            }
            max = Math.max(max, sum);
        }

        return max;
    }

    // scadere de linii
    public static double[] subtractLineFromLine(double X[], double Y[])
            throws Exception {
        if (X == null) {
            throw new Exception("subtractLineFromLine: invalid X");
        }

        if (Y == null) {
            throw new Exception("subtractLineFromLine: invalid Y");
        }

        if (X.length != Y.length) {
            throw new Exception("subtractLineFromLine: invalid sizes");
        }

        int N = X.length;
        double Z[] = new double[N];

        for (int i = 0; i < N; i++) {
            Z[i] = X[i] - Y[i];
        }

        return Z;
    }

    // scadere de matrici
    public static double[][] subtractSquareFromSquare(double X[][],
            double Y[][]) throws Exception {
        if (X == null) {
            throw new Exception("subtractSquareFromSquare: invalid X");
        }

        if (Y == null) {
            throw new Exception("subtractSquareFromSquare: invalid Y");
        }

        if (X.length != Y.length) {
            throw new Exception("subtractLineFromLine: invalid sizes");
        }

        for (int i = 0; i < X.length; ++i) {
            if (X[i].length != Y[i].length || X[i].length != X.length) {
                throw new Exception("subtractLineFromLine: invalid sizes");
            }
        }

        int N = X.length;
        double Z[][] = new double[N][N];

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; i++) {
                Z[i][j] = X[i][j] - Y[i][j];
            }
        }

        return Z;
    }

    // inmultire de matrice cu linie
    public static double[] multiplySquareWithLine(double A[][], double X[])
            throws Exception {
        if (A == null) {
            throw new Exception("multiplySquareWithLine: invalid A");
        }

        if (X == null) {
            throw new Exception("multiplySquareWithLine: invalid X");
        }

        if (A.length != X.length) {
            throw new Exception("multiplySquareWithLine: invalid sizes");
        }

        for (int i = 0; i < X.length; ++i) {
            if (A[i].length != X.length) {
                throw new Exception("multiplySquareWithLine: invalid sizes");
            }
        }

        int N = A.length;
        double Y[] = new double[N];
        Y[0] = N;

        for (int i = 0; i < N; i++) {
            Y[i] = 0;
            for (int j = 0; j < N; j++) {
                Y[i] += A[i][j] * X[j];
            }
        }

        return Y;
    }

    // inmultire de matrici
    public static double[][] multiplySquareWithSquare(double X[][],
            double Y[][]) throws Exception {
        if (X == null) {
            throw new Exception("multiplySquareWithSquare: invalid X");
        }

        if (Y == null) {
            throw new Exception("multiplySquareWithSquare: invalid Y");
        }

        if (X.length != Y.length) {
            throw new Exception("subtractLineFromLine: invalid sizes");
        }

        for (int i = 0; i < X.length; ++i) {
            if (X[i].length != Y[i].length || X[i].length != X.length) {
                throw new Exception("subtractLineFromLine: invalid sizes");
            }
        }

        int N = X.length;
        double Z[][] = new double[N][N];

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; i++) {
                Z[i][j] = 0;
                for (int k = 0; k < N; ++k) {
                    Z[i][j] += X[i][k] * Y[k][j];
                }
            }
        }

        return Z;
    }

    // inmultire de matrici cu retinerea rezultatului in matricea B
    public static void multiplySquareWithSquareInPlace(double A[][],
            double B[][]) throws Exception {
        if (A == null) {
            throw new Exception("multiplySquareWithSquareInPlace: invalid A");
        }

        if (B == null) {
            throw new Exception("multiplySquareWithSquareInPlace: invalid B");
        }

        double R[][] = multiplySquareWithSquare(A, B);

        int N = A.length;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                B[i][j] = R[i][j];
            }
        }
    }

    // inmultire de matrice cu coloana, cu retinerea rezultatului in coloana
    public static void multiplySquareWithLineInPlace(double A[][], double b[])
            throws Exception {
        if (A == null) {
            throw new Exception("multiplySquareWithLineInPlace: invalid A");
        }

        if (b == null) {
            throw new Exception("multiplySquareWithLineInPlace: invalid b");
        }

        double r[] = multiplySquareWithLine(A, b);
        int N = b.length;

        for (int i = 0; i < N; ++i) {
            b[i] = r[i];
        }
    }

    // inmulteste matricea a cu matricea de rotatie pq avand coeficientii c si s
    public static void computeRsquare(int p, int q, double c, double s,
            double A[][], double E) throws Exception {
        if (Math.abs(c * c + s * s - 1) > E) {
            throw new Exception("computeRsquare: invalid values c and s");
        }

        for (int i = 0; i < A.length; ++i) {
            if (A[i].length != A.length) {
                throw new Exception("computeRsquare: invalid sizes");
            }
        }

        if (!(0 <= p && p < A.length && 0 <= q && q < A.length)) {
            throw new Exception("computeRsquare: invalid values p and q");
        }

        for (int k = 0; k < A.length; ++k) {
            double Vpk = A[p][k], Vqk = A[q][k];
            A[p][k] = c * Vpk + s * Vqk;
            A[q][k] = c * Vqk - s * Vpk;
        }
    }

    // inmulteste matricea de rotatie pq cu coloana a, cu coeficientii c si s
    // retine rezultatul in matricea a
    public static void computeRline(int p, int q, double c, double s,
            double A[], double E) throws Exception {
        if (Math.abs(c * c + s * s - 1) > E) {
            throw new Exception("computeRline: invalid values c and s");
        }

        if (!(0 <= p && p < A.length && 0 <= q && q < A.length)) {
            throw new Exception("computeRline: invalid values p and q");
        }

        double Vp = A[p], Vq = A[q];
        A[p] = c * Vp + s * Vq;
        A[q] = c * Vq - s * Vp;
    }

    // rezolva sistemul liniar superior triunghiular
    public static double[] computeXsuperior(double A[][], double B[], double E)
            throws Exception {
        if (A == null) {
            throw new Exception("computeXsuperior: invalid A");
        }

        if (B == null) {
            throw new Exception("computeXsuperior: invalid B");
        }

        if (A.length != B.length) {
            throw new Exception("computeXsuperior: invalid sizes");
        }

        for (int i = 0; i < A.length; ++i) {
            if (A[i].length != B.length) {
                throw new Exception("computeXsuperior: invalid sizes");
            }
        }

        int N = A.length;
        double X[] = new double[N];

        for (int i = N - 1; i >= 0; --i) {
            X[i] = B[i];

            for (int j = N - 1; j > i; --j) {
                X[i] -= A[i][j] * X[j];
            }

            if (Math.abs(A[i][i]) <= E) {
                throw new Exception("computeXsuperior: division by 0");
            }

            X[i] /= A[i][i];
        }

        return X;
    }

    // calculeaza descompuenerea qr, retinand R in A
    public static void computeGivensInPlace(double q[][], double A[][],
            double b[], double E) throws Exception {
        if (q == null) {
            throw new Exception("computeGivensInPlace: invalid q");
        }

        if (A == null) {
            throw new Exception("computeGivensInPlace: invalid A");
        }

        if (b == null) {
            throw new Exception("computeGivensInPlace: invalid b");
        }

        if (q.length != A.length || b.length != A.length) {
            throw new Exception("computeGivensInPlace: invalid sizes");
        }

        for (int i = 0; i < b.length; ++i) {
            if (q[i].length != b.length || A[i].length != b.length) {
                throw new Exception("computeGivensInPlace: invalid sizes");
            }
        }

        int N = A.length;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j && Math.abs(q[i][j] - 1) >= E) {
                    throw new Exception("computeGivensInPlace: invalid q");
                }
                if (i != j && Math.abs(q[i][j]) >= E) {
                    throw new Exception("computeGivensInPlace: invalid q");
                }
            }
        }

        for (int r = 0; r < N - 1; ++r) {
            for (int i = r + 1; i < N; ++i) {
                double R0 = Math.sqrt(A[r][r] * A[r][r] + A[i][r] * A[i][r]);
                double c = (R0 < E ? 1 : A[r][r] / R0);
                double s = (R0 < E ? 0 : A[i][r] / R0);
                // double RR[][] = computeR(N, r, i, c, s, E);

                computeRsquare(r, i, c, s, A, E);
                computeRline(r, i, c, s, b, E);
                computeRsquare(r, i, c, s, q, E);
            }
        }
    }

    public static void transposeSquare(double A[][]) throws Exception {
        if (A == null) {
            throw new Exception("transposeSquare: invalid A");
        }

        for (int i = 0; i < A.length; ++i) {
            if (A[i].length != A.length) {
                throw new Exception("transposeSquare: invalid sizes");
            }
        }

        int N = A.length;
        double a;

        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                a = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = a;
            }
        }
    }

    public static double[][] computeSquareInverse(double Qt[][],
            double R[][], double B[], double E) throws Exception {
        if (Qt == null) {
            throw new Exception("computeSquareInverse: invalid Qt");
        }

        if (R == null) {
            throw new Exception("computeSquareInverse: invalid R");
        }

        if (B == null) {
            throw new Exception("computeSquareInverse: invalid B");
        }

        if (Qt.length != R.length || R.length != B.length) {
            throw new Exception("computeSquareInverse: invalid sizes");
        }

        for (int i = 0; i < B.length; ++i) {
            if (Qt[i].length != B.length || R[i].length != B.length) {
                throw new Exception("computeSquareInverse: invalid sizes");
            }
        }

        int N = B.length;
        double[] b = new double[N];
        double[][] V = new double[N][N];

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                b[i] = Qt[i][j];
            }

            double[] x = Numeric.computeXsuperior(R, b, E);

            for (int i = 0; i < N; ++i) {
                V[i][j] = x[i];
            }
        }

        return V;
    }
    
}
