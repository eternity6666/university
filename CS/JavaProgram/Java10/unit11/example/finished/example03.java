// RectangleFromSimpleGeometricObject.java 
package unit11.example.out;

public class example03 extends example01 {

    private double width;
    private double height;

    public example03() {
    }

    public example03(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public example03(double width, double height, String color, boolean filled) {
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
}

