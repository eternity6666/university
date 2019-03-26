package unit02.exam.out;

import java.util.Scanner;

public class exam23{

    public static void main(String[] args){

        Scanner inner = new Scanner(System.in);

        System.out.print("Enter the driving distance:  ");
        double distance = inner.nextDouble();

        System.out.print("Enter miles per gallon: ");
        double miles = inner.nextDouble();

        System.out.print("Enter price per gallon: ");
        double price = inner.nextDouble();

        System.out.printf("The cost of driving is $%.2f\n", distance / miles * price);
    }
}
