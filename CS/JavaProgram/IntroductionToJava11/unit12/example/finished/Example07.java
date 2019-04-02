// CircleWithException.java

package unit12.example.out;

public class Example07 {
    private double radius;
    private static int numberOfObjects = 0;

    public Example07() {
        this(1.0);
    }

    public Example07(double radius) {
        setRadius(radius);
        numberOfObjects++;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) throws IllegalArgumentException {
        if (radius >= 0)
            this.radius = radius;
        else
            throw new IllegalArgumentException("Radius cannot be negative");
    }

    public static int getNumberOfObjects() {
        return numberOfObjects;
    }

    public double findArea() {
        return radius * radius * Math.PI;
    }
}

