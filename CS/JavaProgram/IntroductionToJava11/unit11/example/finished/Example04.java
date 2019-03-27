// TestCircleRectangle.java
package unit11.example.out;

import unit11.example.out.Example02;
import unit11.example.out.Example03;

public class Example04 {

    public static void main(String[] args) {

        Example02 circle = new Example02(1);
        System.out.println("A circle " + circle.toString());
        System.out.println("The color is " + circle.getColor());
        System.out.println("The filled is " + circle.isFilled());
        System.out.println("The radius is " + circle.getRadius());
        System.out.println("The area is " + circle.getArea());
        System.out.println("The diameter is " + circle.getDiameter());

        Example03 rectangle = new Example03(2, 4);
        System.out.println("\nA rectangle " + rectangle.toString());
        System.out.println("The area is " + rectangle.getArea());
        System.out.println("The perimeter is " + rectangle.getPerimeter());
    }
}

