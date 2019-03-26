// CastingDemo.java
package unit11.example.out;

import unit11.example.out.Example02;
import unit11.example.out.Example03;

public class Example07 {

    public static void main(String[] args) {

        Object object1 = new Example02(1);
        Object object2 = new Example03(1, 1);

        displayObject(object1);
        displayObject(object2);
    }

    public static void displayObject(Object object) {

        if(object instanceof Example02) {
            System.out.println("The circle area is " + ((Example02)object).getArea());
            System.out.println("The circle diameter is " + ((Example02)object).getDiameter());
        }
        else if(object instanceof Example03) {
            System.out.println("The rectangle area is " + ((Example03)object).getArea());
        }
    }
}

