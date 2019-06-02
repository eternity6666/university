package unit05.example.out;

import java.util.*;

public class Example04{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of questions: ");
        int numberOfQuestion = input.nextInt();
        int countCorrent = 0;
        String output = "";

        long startTime = System.currentTimeMillis();
        for(int i = 1; i <= numberOfQuestion; i++){
            int number1 = (int)(Math.random() * 10);
            int number2 = (int)(Math.random() * 10);
            
            if(number1 < number2){
                int tmp = number1;
                number1 = number2;
                number2 = tmp;
            }

            System.out.print("What is " + number1 + " - " + number2 + "? ");
            int answer = input.nextInt();

            if(number1 - number2 == answer){
                countCorrent++;
                System.out.println("You are corrent.\n");
            }
            else
                System.out.println("Your answer is wrong.\n" + number1 + " - " + number2 + " shoud be " + (number1 - number2) + "\n");
            
            output += "\n" + number1 + " - " + number2 + " = " + answer + ((number1 - number2 == answer) ? " corrent" : " wrong");
        }
        long endTime = System.currentTimeMillis();

        long testTime = endTime - startTime;
        System.out.println("Corrent count is " + countCorrent + "\nTest time is " + testTime / 1000 + " seconds\n" + output);
    }
}

