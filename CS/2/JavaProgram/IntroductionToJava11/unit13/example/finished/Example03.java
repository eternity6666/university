// Rectangle.java

package unit13.example.out;

import unit13.example.out.Example01;

public class Example03 extends Example01 {

    private double width;
    private double height;

    public Example03() {
    }

    public Example03(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public Example03(double width, double height, String color, boolean filled) {
        this.width = width;
        this.height = height;
        setColor(color);
        setFilled(filled);
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return 2 * width + 2 * height;
    }

    @Override
    public String toString() {
        return "Width: " + width + " Height: " + height;
    }
}

