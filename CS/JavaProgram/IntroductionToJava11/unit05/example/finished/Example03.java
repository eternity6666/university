package unit05.example.out;

import java.util.*;

public class Example03{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        int number = (int)(Math.random() * 101);

        System.out.println("Guess a magic number between 0 and 100");

        int guess = -1;
        while(guess != number)
        {
            System.out.print("Enter your guess: ");
            guess = input.nextInt();

            if (guess == number)
                System.out.println("Yes, the number is " + number);
            else if(guess > number)
                System.out.println("Your guess is too high.");
            else
                System.out.println("Your guess is too low.");
        }
    }
}

