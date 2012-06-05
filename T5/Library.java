package cn5;

import java.io.BufferedWriter;
import java.util.Random;

import Jama.Matrix;
import Jama.SingularValueDecomposition;

public class Library {

	public static boolean matrixIsSymmetric(double M[][], double EPS)
			throws Exception {

		if (M == null)
			throw new Exception("[matrixIsSymmetric] null argument");

		for (int i = 0; i < M.length; i++)
			if (M[i].length != M.length) {
				throw new Exception("[matrixIsSymmetric] invalid argument");
				// return false;
			}

		boolean ans = true;
		for (int i = 0; i < M.length; i++) {
			for (int j = 0; j < i; j++)
				if (M[i][j] - M[j][i] > EPS) {
					ans = false;
					break;
				}
		}
		return ans;
	}

	public static double ScalarProductBetween(double x1[], double x2[])
			throws Exception {
		double ans = 0;

		if (x1.length != x2.length)
			throw new Exception("[euclidianNorm] invalid arguments");

		for (int i = 0; i < x1.length; i++)
			ans += Math.abs(x1[i] * x2[i]);

		return ans;
	}

	public static double euclidianNorm(double V[]) throws Exception {
		double ans = 0;

		ans = ScalarProductBetween(V, V);
		ans = Math.sqrt(ans);

		return ans;
	}

	public static double[] multiplyLineWithDouble(double V[], double e)
			throws Exception {
		if (V == null)
			throw new Exception("[multiplyLineWithDouble] null argument");

		double ans[] = new double[V.length];

		for (int i = 0; i < V.length; i++)
			ans[i] = V[i] * e;

		return ans;
	}

	public static double[][] multiplySquareWithDouble(double A[][], double e)
			throws Exception {

		if (A == null)
			throw new Exception("[multiplySquareWithDouble] null argument");

		double ans[][] = new double[A.length][];

		for (int i = 0; i < A.length; i++) {
			ans[i] = new double[A[i].length];

			for (int j = 0; j < A[i].length; j++) {
				ans[i][j] = A[i][j] * e;
			}
		}

		return ans;
	}

	public static double[] powerMethod(double A[][], int n, int p, double EPS,
			int KMAX) throws Exception {

		// test if argument exists
		if (A == null)
			throw new Exception("[powerMethod] null argument matrix");

		// test if matrix is valid (symmetric)
		if (matrixIsSymmetric(A, EPS) == false)
			throw new Exception("[powerMethod] invalid matrix (notasymmetric)");

		// declare the current element for the array list
		double X[] = new double[n];

		// start with an vector with the euclidian norm = 1.
		Random rand = new Random();

		for (int i = 0; i < n; i++)
			X[i] = rand.nextDouble();

		double pVal = euclidianNorm(X);

		for (int i = 0; i < n; i++)
			X[i] = X[i] / pVal;

		double W[] = new double[n];
		W = Numeric.multiplySquareWithLine(A, X);

		pVal = ScalarProductBetween(W, X);

		int k = 0;

		do {
			// calculez urmatorul vector posibil
			X = multiplyLineWithDouble(W, 1.00 / euclidianNorm(W));

			W = Numeric.multiplySquareWithLine(A, X);

			pVal = ScalarProductBetween(W, X);

			double t[] = Numeric.subtractLineFromLine(W,
					multiplyLineWithDouble(X, pVal));

			boolean tempOk = true;
			for (int i = 0; i < t.length; i++)
				if (Math.abs(t[i]) > (n * EPS)) {
					// am gasit un element diferit de 0.
					tempOk = false;
					break;
				}

			// daca nu am gasit nici un element mai mare decat n * EPS => dif.
			// este 0!!
			if (tempOk == true) {
				break;
			} else
				k++;

		} while (k <= KMAX);

		double ans[] = new double[A.length];

		// ans[0] - retin valoarea proprie asociat vectorului ans
		ans[0] = pVal;

		// ans 1..n retin vectorul propriu asociat valorii proprii respective
		for (int i = 1; i < n; i++)
			ans[i] = X[i - 1];

		return ans;
	}

	public static double[] reversedIterationMethod(double A[][], int n, int p,
			double miu, double EPS, int KMAX) throws Exception {

		// test if argument exists
		if (A == null)
			throw new Exception("[reverseIteration] null argument matrix");

		// test if matrix is valid (symmetric)
		if (matrixIsSymmetric(A, EPS) == false)
			throw new Exception(
					"[reverseIteration] invalid matrix (notasymmetric)");

		// declare the current element for the array list
		double X[] = new double[n];

		// start with an vector with the euclidian norm = 1.
		Random rand = new Random();

		for (int i = 0; i < n; i++)
			X[i] = rand.nextDouble();

		double pVal = euclidianNorm(X);

		for (int i = 0; i < n; i++)
			X[i] = X[i] / pVal;

		double W[], Z[], d[][] = new double[A.length][A.length];

		// compute d = A - miu * In;
		for (int i = 0; i < A.length; i++)
			for (int j = 0; j < A[i].length; j++) {
				if (i == j)
					d[i][j] = A[i][j] - miu;
				else
					d[i][j] = A[i][j];
			}

		Matrix D = new Matrix(d);

		int k = 0;

		do {

			// dW = X
			double x[][] = new double[X.length][1];
			for (int i = 0; i < X.length; i++)
				x[i][0] = X[i];

			W = D.solve(new Matrix(x)).getColumnPackedCopy();

			// compute vk in X
			X = multiplyLineWithDouble(W, 1.00 / euclidianNorm(W));

			Z = Numeric.multiplySquareWithLine(A, X);

			pVal = ScalarProductBetween(Z, X);

			double t[] = Numeric.subtractLineFromLine(Z,
					multiplyLineWithDouble(X, pVal));

			boolean tempOk = true;
			for (int i = 0; i < t.length; i++)
				if (Math.abs(t[i]) > (n * EPS)) {
					// am gasit un element diferit de 0.
					tempOk = false;
					break;
				}

			// daca nu am gasit nici un element mai mare decat n * EPS => dif.
			// este 0!!
			if (tempOk == true) {
				break;
			} else
				k++;

		} while (k <= KMAX);

		double ans[] = new double[A.length];

		// ans[0] - retin valoarea proprie asociat vectorului ans
		ans[0] = pVal;

		// ans 1..n retin vectorul propriu asociat valorii proprii respective
		for (int i = 1; i < n; i++)
			ans[i] = X[i - 1];

		return ans;
	}

	public static int writeMatrix(double M[][], BufferedWriter file)
			throws Exception {

		if (M == null)
			throw new Exception("[writeMatrix] null argument");

		// calculez numarul maxim de elemente pe o coloana, pentru a incadra
		// matricea care o printez la momentul curent
		int max = 0;

		for (int i = 0; i < M.length; i++)
			if (max < M[i].length)
				max = M[i].length;

		if (file != null) {
			// write the matrix in file

			for (int i = 0; i < 11 * max; i++)
				file.write("-");

			file.write("\n");
			for (int i = 0; i < M.length; i++) {
				for (int j = 0; j < M[i].length; j++)
					file.write(M[i][j] + " ");

				file.write("\n");
			}

			for (int i = 0; i < 11 * max; i++)
				file.write("-");

			file.write("\n");
			file.flush();

			return max;
		}

		for (int i = 0; i < 11 * max; i++)
			System.out.print("-");

		System.out.println();
		for (int i = 0; i < M.length; i++) {
			for (int j = 0; j < M[i].length; j++)
				System.out.print(M[i][j] + " ");

			System.out.println();
		}

		for (int i = 0; i < 11 * max; i++)
			System.out.print("-");

		System.out.println();

		return max;
	}

	public static void SingleValueDecomposition(double M[][], int p, int n,
			double b[], double EPS, BufferedWriter out) throws Exception {

		if (M == null)
			throw new Exception(
					"[SingleValueDecomposition] null matrix argument");

		if (M.length != p)
			throw new Exception("[SingleValueDecomposition] invalid p");

		for (int i = 0; i < p; i++)
			if (M[i].length != n)
				throw new Exception("[SingleValueDecomposition] invalid n");

		if (b.length != p)
			throw new Exception("[SingleValueDecomposition] invalid b array");

		Matrix A = new Matrix(M);

		SingularValueDecomposition d = new SingularValueDecomposition(A);

		Matrix U = (Matrix) d.getU();
		Matrix S = (Matrix) d.getS();
		Matrix V = (Matrix) d.getV();

		int min = (int) Math.min(n, p), rang = 1;
		double mv = S.get(0, 0), Mv = S.get(0, 0);

		if (out == null)
			System.out
					.print("[SingleValueDecomposition]The singular values are: "
							+ S.get(0, 0));
		else
			out.write("[SingleValueDecomposition]The singular values are: "
					+ S.get(0, 0));

		for (int i = 1; i < min; i++) {
			double v = S.get(i, i);

			if (out == null)
				System.out.print(" " + v);
			else
				out.write(" " + v);

			if (Math.abs(v) > EPS)
				rang++;

			if (v > Mv)
				Mv = v;

			if (Math.abs(v) > EPS && v < mv)
				mv = v;
		}
		if (out == null)
			System.out.println();
		else
			out.write("\n");

		if (out == null)
			System.out.println("[SingleValueDecomposition]The Matrix rang is: "
					+ rang + "\n");
		else
			out.write("[SingleValueDecomposition]The Matrix rang is " + rang
					+ "\n");

		if (Math.abs(mv) > EPS) {
			if (out == null)
				System.out
						.println("[SingleValueDecomposition]The conditionary matrix value is: "
								+ (Mv / mv) + "\n");
			else
				out
						.write("[SingleValueDecomposition]The conditionary matrix value is: "
								+ (Mv / mv) + "\n");
		} else {
			if (out == null)
				System.out
						.println("[SingleValueDecomposition]The conditionary matrix value can't be computed. It has only 0 singular values."
								+ "\n");
			else
				out
						.write("[SingleValueDecomposition]The conditionary matrix value can't be computed. It has only 0 singular values."
								+ "\n");
		}

		Matrix usv = U.times(S).times(V.transpose());

		Matrix rez = A.minus(usv);

		if (out == null)
			System.out
					.println("[SingleValueDecomposition]The Infinity Norm || A - USVt || is: "
							+ rez.normInf() + "\n");
		else
			out
					.write("[SingleValueDecomposition]The Infinity Norm || A - USVt || is:"
							+ rez.normInf() + "\n");

		// calculate the Moore Penrose Matrix double
		// double Si[][] = new double[n][p];
		double Si[][] = new double[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j && i < rang)
					Si[i][j] = 1 / S.get(i, j);
				else
					Si[i][j] = 0;
			}

		Matrix MPSi = new Matrix(Si);
		
		Matrix MPm = V.times(MPSi);
		MPm = MPm.times(U.transpose());
		
		if (out == null)
			System.out
					.println("[SingleValueDecomposition]The Moore Penrose Matrix is:"
							+ "\n");
		else
			out.write("[SingleValueDecomposition]The Moore Penrose Matrix is: "
					+ "\n");
		writeMatrix(MPm.getArray(), out);

		if (out == null)
			System.out
					.println("[SingleValueDecomposition]The sistem solution for Ax = b, xi = Ai*b is:"
							+ "\n");
		else
			out
					.write("[SingleValueDecomposition]The sistem solution for Ax = b, xi = Ai*b is:"
							+ "\n");

		if (p != b.length)
			throw new Exception("SingularValueDecomposition: invalid b size");

		double bb[][] = new double[p][1];

		for (int i = 0; i < b.length; i++)
			bb[i][0] = b[i];

		Matrix B = new Matrix(bb);
		Matrix XI = MPm.times(B);
		writeMatrix(XI.getArray(), out);

		if (out == null)
			System.out
					.println("[SingleValueDecomposition]Norm2 || b - A * XI || = "
							+ B.minus(A.times(XI)).norm2() + "\n");
		else
			out.write("[SingleValueDecomposition]Norm2 || b - A * XI || = "
					+ B.minus(A.times(XI)).norm2() + "\n");

		if (out == null)
			System.out.println("[SingleValueDecomposition]Norm2 || XI || = "
					+ XI.norm2() + "\n");
		else
			out.write("[SingleValueDecomposition]Norm2 || XI || = "
					+ XI.norm2() + "\n");
	}

	public static double[][] generateMatrix(int rows, int cols)
			throws Exception {
		double ans[][] = new double[rows][cols];

		Random rand = new Random();

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				ans[i][j] = rand.nextDouble();
		return ans;
	}

	public static double[][] generateSymmetricMatrix(int dim) throws Exception {
		double ans[][] = new double[dim][dim];

		Random rand = new Random();

		for (int i = 0; i < dim; i++)
			for (int j = 0; j < i; j++) {
				double r = rand.nextDouble();
				ans[i][j] = r;
				ans[j][i] = r;
			}

		return ans;
	}

	public static double[] generateArray(int dim) throws Exception {
		double ans[] = new double[dim];

		Random rand = new Random();

		for (int i = 0; i < dim; i++) {
			ans[i] = rand.nextDouble();
		}
		return ans;
	}

	public static double[][] getArrayCopy(Matrix A) {
		double[][] ans = new double[A.getRowDimension()][A.getColumnDimension()];

		System.out.println(A.getRowDimension());
		System.out.println(A.getColumnDimension());

		for (int i = 0; i < A.getRowDimension(); i++) {
			for (int j = 0; j < A.getColumnDimension(); j++) {
				System.out.print(A.get(i, j) + " ");
				ans[i][j] = A.get(i, j);
			}
			System.out.println();
		}

		return ans;
	}
}
