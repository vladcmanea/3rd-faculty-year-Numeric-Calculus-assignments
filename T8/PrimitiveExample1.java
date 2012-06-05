package cn8;

public class PrimitiveExample1 extends Primitive {

    public PrimitiveExample1(double a, double b, int N) throws Exception {
        super(a, b, N);
    }

    public double f(double x) {
        return 4.0 * Math.pow(x, 2) * (2.0 * x - 1);
    }

    public double F(double x) {
        return 2.0 * Math.pow(x, 3) * (x - 2.0 / 3.0);
    }
    
}
