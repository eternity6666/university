// Rational.java

package unit13.example.out;

import java.lang.Number;

public class Example13 extends Number implements Comparable<Example13> {
    private long numerator;
    private long denominator;

    public Example13() {
        this(0, 1);
    }

    public Example13(long numerator, long denominator) {
        long tmp = gcd(numerator, denominator);
        this.numerator = ((denominator > 0) ? 1 : -1) * numerator / tmp;
        this.denominator = Math.abs(denominator) / tmp;
    }

    private long gcd(long a, long b) {
        long n = Math.abs(a);
        long d = Math.abs(b);
        if(d == 0)
            return n;
        else
            return gcd(d, n % d);
    }

    public long getNumerator() {
        return numerator;
    }

    public long getDenominator() {
        return denominator;
    }

    public Example13 add(Example13 secondRational) {
        long newNumerator = numerator * secondRational.getDenominator() + denominator * secondRational.getNumerator();
        long newDenominator = denominator * secondRational.getDenominator();
        return new Example13(newNumerator, newDenominator);
    }

    public Example13 subtract(Example13 secondRational) {
        long newNumerator = numerator * secondRational.getDenominator() - denominator * secondRational.getNumerator();
        long newDenominator = denominator * secondRational.getDenominator();
        return new Example13(newNumerator, newDenominator);
    }

    public Example13 multiply(Example13 secondRational) {
        return new Example13(numerator * secondRational.getNumerator(), denominator * secondRational.getDenominator());
    }

    public Example13 divide(Example13 secondRational) {
        return new Example13(numerator * secondRational.getDenominator(), denominator * secondRational.getNumerator());
    }

    @Override
    public String toString() {
        if(denominator == 1)
            return numerator + "";
        else
            return numerator + "/" + denominator;
    }

    @Override
    public boolean equals(Object other) {
        if((this.subtract((Example13)(other))).getNumerator() == 0)
            return true;
        else
            return false;
    }

    @Override
    public int intValue() {
        return (int)doubleValue();
    }

    @Override
    public float floatValue() {
        return (float)doubleValue();
    }

    @Override
    public double doubleValue() {
        return numerator * 1.0 / denominator;
    }

    @Override
    public long longValue() {
        return (long)doubleValue();
    }

    @Override
    public int compareTo(Example13 o) {
        if(this.subtract(o).getNumerator() > 0)
            return 1;
        else if(this.subtract(o).getNumerator() < 0)
            return -1;
        else
            return 0;
    }
}

