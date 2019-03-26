// PolymorphismDemo
package unit11.example.out;

import unit11.example.out.Example02;
import unit11.example.out.Example03;

public class Example05 {

    public static void main(String[] args) {

        displayObject(new Example02(1, "red", false));
        displayObject(new Example03(1, 1, "black", true));
    }

    public static void displayObject(Example01 object) {
        System.out.println("Created on " + object.getDateCreated() + ". Color is " + object.getColor());
    }
}

