// TestCircleWithException.java
package unit12.example.out;

import unit12.example.out.Example07;

public class Example08 {
    public static void main(String[] args) {
        try {
            Example07 c1 = new Example07(5);
            Example07 c2 = new Example07(-5);
            Example07 c3 = new Example07(0);
        }
        catch (IllegalArgumentException ex) {
            System.out.println(ex);
        }

        System.out.println("Number of objects created: " + Example07.getNumberOfObjects());
    }
}

