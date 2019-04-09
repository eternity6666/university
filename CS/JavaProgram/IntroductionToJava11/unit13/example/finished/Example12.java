// TestRationalClass.java

package unit13.example.out;

import unit13.example.out.Example13;

public class Example12 {
    public static void main(String[] args) {
        Example13 r1 = new Example13(4, 2);
        Example13 r2 = new Example13(2, 3);

        System.out.println(r1 + " + " + r2 + " = " + r1.add(r2));
        System.out.println(r1 + " - " + r2 + " = " + r1.subtract(r2));
        System.out.println(r1 + " * " + r2 + " = " + r1.multiply(r2));
        System.out.println(r1 + " / " + r2 + " = " + r1.divide(r2));
        System.out.println(r2 + " is " + r2.doubleValue());
    }
}

