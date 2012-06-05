package cn8;

public class PrimitiveExample2 extends Primitive {

    public PrimitiveExample2(double a, double b, int N) throws Exception {
        super(a, b, N);
    }

    public double f(double x) {
        return -Math.sin(x) + 2.0 * x + Math.pow(x, 2);
    }

    public double F(double x) {
        return Math.cos(x) + Math.pow(x, 2) + Math.pow(x, 3) / 3.0;
    }

}
