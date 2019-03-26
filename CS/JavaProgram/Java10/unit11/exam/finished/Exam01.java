package unit11.exam.out;

import unit11.example.out.Example01;

public class Exam01 extends Example01 {

    public static void mian(String[] args) {
        Exam01 test = new Exam01();
    }

    private double side1 = 1.0;
    private double side2 = 1.0;
    private double side3 = 1.0;

    public Exam01() {
        this(1.0, 1.0, 1.0);
    }

    public Exam01(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getSide1() {
        return side1;
    }

    public void setSide1(double side1) {
        this.side1 = side1;
    }

    public double getSide2() {
        return side2;
    }

    public void setSide2(double side2) {
        this.side1 = side1;
    }

    public double getSide3() {
        return side3;
    }

    public void setSide3(double side3) {
        this.side1 = side1;
    }

    public double getArea() {
        return Math.sqrt(getPerimeter() * (getPerimeter() - side1) * (getPerimeter() - side2) * (getPerimeter() - side3));
    }

    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    public String toString() {
        return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
    }
}


