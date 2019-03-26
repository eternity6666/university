package unit03.exam.out;

import java.util.*;

public class exam09{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the first 9 digits of an ISBN as integer: ");
        String isbn = input.nextLine();

        int isbn10 = ISBN10(isbn);

        System.out.print("The ISBN-10 number is " + isbn);
        if(isbn10 < 10)
            System.out.println(isbn10);
        else
            System.out.println("X");
    }

    public static int ISBN10(String isbn){

        int sum = 0;

        int len = isbn.length();

        for(int i = 0; i < len; i++)
        {
            sum = sum + (isbn.charAt(i) - '0') * (i + 1);
        }
        return sum % 11;
    }
}

