package cn8;

import java.util.Scanner;

public class Main {

    private static void example(Primitive primitive)
            throws Exception {
        double Iexact = primitive.getIntegralExact();
        double Ifirst = primitive.getIntegralWithFirstMethod();
        double Isecond = primitive.getIntegralWithSecondMethod();

        System.out.println(Iexact + " " + Ifirst + " " + Isecond + " "
                + Math.abs(Iexact - Ifirst) + " " + Math.abs(Iexact - Isecond));
    }

    public static void main(String[] args) throws Exception {

        Scanner scanner = new Scanner(System.in);
        double a = Double.parseDouble(scanner.next());
        double b = Double.parseDouble(scanner.next());
        int N = Integer.parseInt(scanner.next());

        example(new PrimitiveExample1(a, b, N));
        example(new PrimitiveExample2(a, b, N));
        example(new PrimitiveExample3(a, b, N));
    }
}
