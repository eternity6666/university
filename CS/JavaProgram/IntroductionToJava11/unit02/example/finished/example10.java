package unit02.example.out;

import java.util.Scanner;

public class example10{
    public static void main(String[] args){
        
        Scanner inner = new Scanner(System.in);

        System.out.print("请输入十进制数作为总数: ");
        double userInput = inner.nextDouble();
        long tmpUserInput = (long)(userInput * 100);

        long dollar, quarter, dime, nickel, penny;

        dollar = tmpUserInput / 100;
        tmpUserInput %= 100;

        quarter = tmpUserInput / 25;
        tmpUserInput %= 25;

        nickel = tmpUserInput / 10;
        tmpUserInput %= 10;
        
        dime = tmpUserInput / 5;
        tmpUserInput %= 5;

        penny = tmpUserInput;

        System.out.println("Your amount " + userInput + " consists of");
        System.out.println("    " + dollar + " dollars");
        System.out.println("    " + quarter + " quarters");
        System.out.println("    " + dime + " dimes");
        System.out.println("    " + nickel + " nickels");
        System.out.println("    " + penny + " pennies");
    }
}
