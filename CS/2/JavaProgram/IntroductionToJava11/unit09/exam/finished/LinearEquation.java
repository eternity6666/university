package unit09.exam.out;

public class LinearEquation {
    private double a;
    private double b;
    private double c;
    private double d;
    private double e;
    private double f;

    public LinearEquation() {
        this(0, 0, 0, 0, 0, 0);
    }

    public LinearEquation(double a, double b, double e, double c, double d, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }

    public double getA() {
        return this.a;
    }

    public double getB() {
        return this.b;
    }
    
    public double getC() {
        return this.c;
    }

    public double getD() {
        return this.d;
    }

    public double getE() {
        return this.e;
    }

    public double getF() {
        return this.f;
    }

    public boolean isSolvable() {
        return getA() * getD() - getB() * getC() != 0;
    }

    public double getX() {
        return (getE() * getD() - getB() * getF()) / (getA() * getD() - getB() * getC());
    }

    public double getY() {
        return (getA() * getF() - getE() * getC()) / (getA() * getD() - getB() * getC());
    }
}

