// TestCircleWithCustomException.java

package unit12.example.out;

import unit12.example.out.Example10;

public class Example11 {
    
    public static void main(String[] args) {
        try {
            new CircleWithCustomException(5);
            new CircleWithCustomException(-5);
            new CircleWithCustomException(0);
        }
        catch (Example10 ex) {
            System.out.println(ex);
        }

        System.out.println("Number of objects created: " + CircleWithCustomException.getNumberOfObjects());
    }
}

class CircleWithCustomException {

    private double radius;

    private static int numberOfObjects = 0;

    public CircleWithCustomException() throws Example10 {
        this(1.0);
    }

    public CircleWithCustomException(double radius) throws Example10 {
        setRadius(radius);
        numberOfObjects++;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) throws Example10{
        if (radius >= 0)
            this.radius = radius;
        else
            throw new Example10(radius);
    }

    public static int getNumberOfObjects() {
        return numberOfObjects;
    }

    public double findArea() {
        return radius * radius * Math.PI;
    }
}

