package unit10.example.out;

import java.util.Scanner;

public class Example01 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.print("Enter annual interest rate, for Example, 8.25: ");
        double annualInterestRate = input.nextDouble();

        System.out.print("Enter number of years as an integer: ");
        int numberOfYears = input.nextInt();

        System.out.print("Enter loan amount, for Example, 120000.95: ");
        double loanAmount = input.nextDouble();

        Example02 loan = new Example02(annualInterestRate, numberOfYears, loanAmount);

        System.out.printf("The loan was created on %s\n" + "The monthly payment is %.2f\nThe total payment is %.2f\n", loan.getLoanDate().toString(), loan.getMonthlyPayment(), loan.getTotalPayment());
    }
}

