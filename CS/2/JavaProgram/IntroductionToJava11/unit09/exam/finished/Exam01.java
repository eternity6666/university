package unit09.exam.out;

public class Exam01{

    public static void main(String[] args) {
        Rectangle a = new Rectangle(4, 40);
        Rectangle b = new Rectangle(3.5, 35.9);
        System.out.println(a);
        System.out.println(b);
    }
}

class Rectangle {
    private double width = 1;
    private double height = 1;

    public Rectangle() {
        this(1, 1);
    }

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
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
        return getWidth() * getHeight();
    }

    public double getPerimeter() {
        return 2 * (getWidth() + getHeight());
    }

    @Override
    public String toString() {
        return "width: " + getWidth() + " height: " + getHeight() + " area: " + getArea() + " perimeter: " + getPerimeter();
    }
}

