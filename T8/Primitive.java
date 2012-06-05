package cn8;

public abstract class Primitive {

    private double a, b, h;
    private int N;

    public Primitive(double a, double b, int N) throws Exception {
        if (N < 10) {
            throw new Exception("Primitive: N is less than 10");
        }

        this.a = a;
        this.b = b;
        this.N = N;
        h = (b - a) / N;
    }

    public abstract double f(double x);

    public abstract double F(double x);

    public double getIntegralExact() {
        return F(b) - F(a);
    }

    public double getIntegralWithFirstMethod() throws Exception {
        if (N % 3 == 0) {

            double R = f(a) + f(b);
            final double _3 = 3.0;
            final double _2 = 2.0;
            final double _8 = 8.0;

            for (int i = 1; i < N; ++i) {
                if (i % 3 == 0) {
                    R += _2 * f(a + i * h);
                } else {
                    R += _3 * f(a + i * h);
                }
            }

            return R * _3 * h / _8;
        }

        return 0;
    }

    public double getIntegralWithSecondMethod() {
        final double _17 = 17.0;
        final double _48 = 48.0;
        final double _59 = 59.0;
        final double _49 = 49.0;
        final double _43 = 43.0;
        final double _2 = 2.0;
        final double _3 = 3.0;
        double R = 0;

        R += (f(a) + f(b)) * _17;
        R += (f(a + h) + f(b - h)) * _59;
        R += (f(a + _2 * h) + f(b - _2 * h)) * _43;
        R += (f(a + _3 * h) + f(b - _2 * h)) * _49;
        R /= 48;

        for (int i = 4; i <= N - 4; ++i) {
            R += f(a + i * h);
        }

        return R * h;
    }
}
