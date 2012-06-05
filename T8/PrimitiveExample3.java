package cn8;

public class PrimitiveExample3 extends Primitive {

    public PrimitiveExample3(double a, double b, int N) throws Exception {
        super(a, b, N);
    }

    public double f(double x) {
        return Math.exp(x) - 2.0 * Math.cos(x) * Math.sin(x);
    }

    public double F(double x) {
        return Math.exp(x) + Math.cos(2.0 * x) / 2.0;
    }
}
