package cn5;

import java.io.*;

public class Main {

	public static void main(String args[]) throws Exception {

		int P, N, kMax;
		double[][] Amatrix = null;
		double[] Barray = null;
		double eps, miuParameter;
		boolean generate = false, generateBarray = false;

		FileWriter outFile = new FileWriter("out.txt");
		BufferedWriter out = new BufferedWriter(outFile);
		FileReader inFile = new FileReader("in.txt");
		BufferedReader in = new BufferedReader(inFile);

		String line = in.readLine();

		String inputValues[] = line.split(" ");

		P = Integer.parseInt(inputValues[0]);
		N = Integer.parseInt(inputValues[1]);
		eps = Double.parseDouble(inputValues[2]);
		kMax = Integer.parseInt(inputValues[3]);
		generate = Boolean.parseBoolean(inputValues[4]);

		out.write("Precision: " + eps + ", maximum number of iteration: "
				+ kMax + "\n");

		out.write("The A matrix ");
		if (generate == true) {
			//Amatrix = Library.generateSymmetricMatrix(P);
			Amatrix = Library.generateMatrix(P, N);
			out.write("generated ");
		} else {

			// read the matrix from the input file
			Amatrix = new double[P][N];
			for (int i = 0; i < P; i++) {
				line = in.readLine();
				inputValues = line.split(" ");
				for (int j = 0; j < N; j++)
					Amatrix[i][j] = Double.parseDouble(inputValues[j]);
			}
		}

		// get the miu parameter and the flag for the Barray generate action
		inputValues = in.readLine().split(" ");
		miuParameter = Double.parseDouble(inputValues[0]);
		generateBarray = Boolean.parseBoolean(inputValues[1]);

		if (P < N) {
			// transpose the matrix to have always P > N
			double[][] temp = new double[N][P];
			for(int i = 0; i < P; i++)
				for(int j = 0; j < N; j++)
					temp[j][i] = Amatrix[i][j];
			
			int aux = P;
			P = N;
			N = aux;
			Amatrix = temp;
		}
		if (generateBarray == true) {
			Barray = Library.generateArray(P);
		} else {

			// read Barray from input file
			line = in.readLine();
			inputValues = line.split(" ");

			if (inputValues.length != P)
				throw new Exception(
						"input B array invalid size. Must be equal with nr. of lines of the matrix");

			Barray = new double[inputValues.length];
			for (int i = 0; i < inputValues.length; i++)
				Barray[i] = Double.parseDouble(inputValues[i]);
		}

		in.close();

		out.write("of dimension (" + P + ", " + N + ") is: \n");
		Library.writeMatrix(Amatrix, out);

		/*
		 * double[] ans = Library.powerMethod(Amatrix, N, M, eps, kMax);
		 * 
		 * out.write("Power Method answer: The proper value found: " + ans[0] +
		 * "\n");
		 * 
		 * out.write("Power Method answer array: "); for (int i = 1; i <
		 * ans.length; i++) out.write(ans[i] + " "); out.write("\n");
		 * 
		 * out.flush();
		 * 
		 * out.write("The miu parameter: " + miuParameter + "\n");
		 * 
		 * 
		 * ans = Library.reversedIterationMethod(Amatrix, N, M, miuParameter,
		 * eps, kMax);
		 * 
		 * 
		 * 
		 * out.write("Reversed Iteration Method answer: The proper value found: "
		 * + ans[0] + "\n");
		 * 
		 * out.write("Reversed Iteration Method answer array: "); for (int i =
		 * 1; i < ans.length; i++) out.write(ans[i] + " "); out.write("\n");
		 * 
		 * out.flush();
		 */

		Library.SingleValueDecomposition(Amatrix, P, N, Barray, eps, out);

		out.flush();
		out.close();
	}

}
