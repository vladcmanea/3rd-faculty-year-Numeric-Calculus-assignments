package cn7;

import Jama.LUDecomposition;
import Jama.Matrix;
import java.util.Scanner;

public class Main {

    public static int N;
    public static int M;
    public static double V;
    public static String input;
    public static Scanner scanner;
    public static double X[];
    public static double Y[];
    public static double G[];
    public static double da;
    public static double db;
    public static double C[];

    private static void preprocessS() {

        // initialize matrix
        G = new double[N + 1];

        // set initial values for length 0
        for (int i = 0; i <= N; ++i) {
            G[i] = Y[i];
        }

        // set values for lengths 1, 2, ..., N and starts 0, 1, ...
        for (int l = 1; l <= N; ++l) {
            for (int i = N; i >= l; --i) {
                G[i] = (G[i] - G[i - 1]) / (X[i] - X[i - l]);
            }
        }
    }

    private static double applyS(double x) {

        double P[];
        double p;
        double A;

        // compute products
        p = 1;
        P = new double[N];
        for (int i = 0; i < N; ++i) {
            P[i] = p = p * (x - X[i]);
        }

        // compute A
        A = G[0];
        for (int i = 1; i <= N; ++i) {
            A += G[i] * P[i - 1];
        }

        // done
        return A;
    }

    private static void preprocessC() {

        // create array T of X differences
        double[] T = new double[N];
        for (int i = 0; i < N; ++i) {
            T[i] = X[i + 1] - X[i];
        }

        // create matrix H
        Matrix H = new Matrix(N + 1, N + 1);
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == j) {
                    if (i == 0) {
                        H.set(i, j, 2 * T[0]);
                    } else if (i == N) {
                        H.set(i, j, 2 * T[N - 1]);
                    } else {
                        H.set(i, j, 2 * (T[i] + T[i - 1]));
                    }
                } else if (i == j + 1) {
                    H.set(i, j, T[j]);
                } else if (j == i + 1) {
                    H.set(i, j, T[i]);
                } else {
                    H.set(i, j, 0);
                }
            }
        }

        // create LU decomposition
        LUDecomposition decomposition = new LUDecomposition(H);

        // create matrix F
        Matrix F = new Matrix(N + 1, 1);
        F.set(0, 0, 6 * ((Y[1] - Y[0]) / T[0] - da));
        F.set(N, 0, 6 * (db - (Y[N] - Y[N - 1]) / T[N - 1]));
        for (int i = 1; i < N; ++i) {
            F.set(i, 0, 6 * (((Y[i + 1] - Y[i]) / T[i])
                    - ((Y[i] - Y[i - 1]) / T[i - 1])));
        }

        Matrix R = decomposition.solve(F);
        C = R.getColumnPackedCopy();
    }

    private static double applyC(double x) {

        int i = N;

        // binary search the index
        for (int l = 0, r = N - 1, m; i == N;) {
            m = (l + r) / 2;

            if (x < X[m]) {
                r = m - 1;
            } else if (x > X[m + 1]) {
                l = m + 1;
            } else {
                i = m;
            }
        }

        // compute the constants
        final double hi = X[i + 1] - X[i];
        final double bi = (Y[i + 1] - Y[i]) / hi - hi * (C[i + 1] - C[i]) / 6;
        final double ci = (X[i + 1] * Y[i] - X[i] * Y[i + 1]) / hi
                - hi * (X[i + 1] * C[i] - X[i] * C[i + 1]) / 6;

        // return the result
        return (Math.pow(x - X[i], 3) * C[i + 1]
                + Math.pow(X[i + 1] - x, 3) * C[i]) / (6 * hi) + bi * x + ci;
    }

    public static void main(String[] args) {

        scanner = new Scanner(System.in);

        // read N
        input = scanner.next();
        N = Integer.parseInt(input);

        // allocate X and Y = f(X) arrays
        X = new double[N + 1];
        Y = new double[N + 1];

        // read all X and Y values
        for (int i = 0; i <= N; ++i) {
            input = scanner.next();
            X[i] = Double.parseDouble(input);
            input = scanner.next();
            Y[i] = Double.parseDouble(input);
        }

        // preprocess S
        preprocessS();

        // read # of questions
        input = scanner.next();
        M = Integer.parseInt(input);

        // read and answer all questions
        for (int m = 0; m < M; ++m) {

            // read X
            input = scanner.next();
            V = Double.parseDouble(input);

            // write S(V)
            System.out.println(applyS(V));
        }

        // read f'(x0)
        input = scanner.next();
        da = Double.parseDouble(input);

        // read f'(xN)
        input = scanner.next();
        db = Double.parseDouble(input);

        // preprocess C
        preprocessC();

        // read # of questions
        input = scanner.next();
        M = Integer.parseInt(input);

        // read and answer all questions
        for (int m = 0; m < M; ++m) {

            // read X
            input = scanner.next();
            V = Double.parseDouble(input);

            // write S(V)
            System.out.println(applyC(V));
        }
    }
}
