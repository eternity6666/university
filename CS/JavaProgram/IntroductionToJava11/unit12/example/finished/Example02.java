// QuotientWithIf.java
package unit12.example.out;

import java.util.Scanner;

public class Example02 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();

        if (number2 != 0)
            System.out.println(number1 + " / " + number2 + " is " + (number1 / number2));
        else
            System.out.println("Divisor cannot be zero.");
    }
}

