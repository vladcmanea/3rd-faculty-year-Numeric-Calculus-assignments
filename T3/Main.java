package cn3;

import Jama.Matrix;
import Jama.QRDecomposition;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

public class Main {

    private static int N;
    private static double E;
    private static boolean G;
    private static double AGivens[][];
    private static double VGivens[][];
    private static double QGivens[][];
    private static double VLibrary[][];
    private static double BGivens[];
    private static double SGivens[];
    private static double XGivens[];
    private static Matrix ALibrary;
    private static Matrix BLibrary;
    private static Matrix SLibrary;
    private static Matrix XLibrary;

    public static void main(String[] args) throws Exception {

        Scanner scanner = new Scanner(new FileReader("cn3.in"));
        PrintWriter printer = new PrintWriter("cn3.out");
        String input;

        // read N
        input = scanner.next();
        N = Integer.parseInt(input);

        // read E
        input = scanner.next();
        E = Double.parseDouble(input);

        // read given
        input = scanner.next();
        G = Boolean.parseBoolean(input);

        // allocate matrix AGivens
        AGivens = new double[N][N];

        // allocate matrix QGivens
        QGivens = new double[N][N];

        // allocate array SGivens
        SGivens = new double[N];

        // get A givens
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G) {
                    input = scanner.next();
                    AGivens[i][j] = Double.parseDouble(input);
                } else {
                    AGivens[i][j] = new Random().nextDouble();
                }
            }
        }

        if (!G) {
            // print the Library matrix A^(-1)
            printer.println("The matrix A is:");
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    printer.print(AGivens[i][j] + " ");
                }
                printer.println();
            }
        }

        // create AGivens copy
        double[][] AGivensCopy = new double[N][N];

        // copy AGivens into AGivens copy
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                AGivensCopy[i][j] = AGivens[i][j];
            }
        }

        // create matrix ALibrary
        ALibrary = new Matrix(AGivens);

        // get S givens
        for (int i = 0; i < N; ++i) {
            if (G) {
                input = scanner.next();
                SGivens[i] = Double.parseDouble(input);
            } else {
                SGivens[i] = new Random().nextDouble();
            }
        }

        if (!G) {
            // print the array S
            printer.println("The array S is:");
            for (int i = 0; i < N; ++i) {
                printer.print(SGivens[i] + " ");
            }
            printer.println();
        }

        // create matrix SLibrary
        SLibrary = new Matrix(SGivens, SGivens.length);

        // set identity matrix Q
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                QGivens[i][j] = (i == j ? 1 : 0);
            }
        }

        /* Problem 1 */

        // compute array BGivens
        BGivens = Numeric.multiplySquareWithLine(AGivens, SGivens);

        // create BGivens copy
        double[] BGivensCopy = new double[N];

        // copy BGivens into BGivens copy
        for (int i = 0; i < N; ++i) {
            BGivensCopy[i] = BGivens[i];
        }

        // compute array BLibrary
        BLibrary = new Matrix(BGivens, BGivens.length);

        // write array BGivens
        printer.println("The array B is:");
        for (int i = 0; i < N; ++i) {
            printer.print(BGivens[i] + " ");
        }
        printer.println();

        /* Problems 2 and 3 */

        // start timer
        long stLibrary = new Date().getTime();

        // compute Library values
        QRDecomposition decomposition = new QRDecomposition(ALibrary);

        // end timer
        long etLibrary = new Date().getTime();

        // start timer
        long stGivens = new Date().getTime();

        // compute Givens values
        Numeric.computeGivensInPlace(QGivens, AGivens, BGivens, E);

        // end timer
        long etGivens = new Date().getTime();

        // print the time difference for Givens
        printer.println("The time for Givens was:");
        printer.println(etGivens - stGivens);

        // print the time difference for Library
        printer.println("The time for Library was:");
        printer.println(etLibrary - stLibrary);

        // print the time difference
        printer.println("The time difference was:");
        printer.println(Math.abs(etGivens - stGivens - etLibrary + stLibrary));

        // compute XGivens
        XGivens = Numeric.computeXsuperior(AGivens, BGivens, E);

        // print the Givens array X
        printer.println("The array XGivens is:");
        for (int i = 0; i < N; ++i) {
            printer.print(XGivens[i] + " ");
        }
        printer.println();

        // compute solution
        XLibrary = decomposition.solve(BLibrary);

        // print the Library array X
        printer.println("The array XLibrary is:");
        for (int i = 0; i < N; ++i) {
            printer.print(XLibrary.get(i, 0) + " ");
        }
        printer.println();

        /* Problem 5 */

        // recreate BGivens
        BGivens = BGivensCopy;

        // compute A^(-1)
        VGivens = Numeric.computeSquareInverse(QGivens, AGivens, BGivens, E);

        // print the Givens matrix A^(-1)
        printer.println("The matrix A^(-1)Givens is:");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printer.print(VGivens[i][j] + " ");
            }
            printer.println();
        }

        // compute inverse of A
        VLibrary = new Matrix(AGivensCopy).inverse().getArrayCopy();

        // print the Library matrix A^(-1)
        printer.println("The matrix A^(-1)Library is:");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printer.print(VLibrary[i][j] + " ");
            }
            printer.println();
        }

        // print the 1-norm Library
        printer.println("The Library Norm-1 inverse is:");
        printer.println(Numeric.Norm1Square(
                Numeric.subtractSquareFromSquare(VGivens, VLibrary)));

        /* Problem 4 */

        // recreate AGivens
        AGivens = AGivensCopy;

        // recreate BGivens
        BGivens = BGivensCopy;

        // print the infinity norm Givens
        printer.println("The Givens NormInf is:");
        printer.println(Numeric.NormInfLine(
                Numeric.subtractLineFromLine(Numeric.multiplySquareWithLine(
                AGivens, XGivens), BGivens)));

        // print the infinity norm Library
        printer.println("The Library NormInf is:");
        printer.println(Numeric.NormInfLine(
                new Matrix(AGivens).times(XLibrary).minus(new Matrix(BGivens,
                BGivens.length)).getColumnPackedCopy()));

        // print the 1-norm Givens
        printer.println("The Givens Norm-1 is:");
        printer.println(Numeric.Norm1Line(
                Numeric.subtractLineFromLine(XGivens, SGivens))
                / Numeric.Norm1Line(SGivens));

        // print the 1-norm Library
        printer.println("The Library Norm-1 is:");
        printer.println(Numeric.Norm1Line(
                XLibrary.minus(new Matrix(SGivens,
                SGivens.length)).getColumnPackedCopy())
                / Numeric.Norm1Line(SGivens));

        scanner.close();
        printer.close();
    }
}
