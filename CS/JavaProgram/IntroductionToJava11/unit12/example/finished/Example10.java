// InvalidRadiusException.java

package unit12.example.out;

public class Example10 extends Exception {
    private double radius;

    public Example10(double radius) {
        super("Invalid radius " + radius);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }
}

