// CircleFromSimpleGeometricObject.java
package unit11.example.out;

import unit11.example.out.Example01;

public class Example02 extends Example01 {

    private double radius;

    public Example02() {
    }

    public Example02(double radius) {
        this.radius = radius;
    }

    public Example02(double radius, String color, boolean filled) {
        this.radius = radius;
        setColor(color);
        setFilled(filled);
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return radius * radius * Math.PI;
    }

    public double getDiameter() {
        return 2 * radius;
    }

    public double getPerimeter() {
        return 2 * radius * Math.PI;
    }

    public void printCircle() {
        System.out.println("The circle is created " + getDateCreated() + " and the radius is " + radius);
    }
}

