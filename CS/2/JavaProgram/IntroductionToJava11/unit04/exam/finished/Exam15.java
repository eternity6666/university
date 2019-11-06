package unit04.exam.out;

import java.util.Scanner;

public class Exam15 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a letter: ");
        String s = input.nextLine();
        char c = s.charAt(0);
        if('A' <= c && c <= 'Z')
            c = (char)((int)'a' + (int)(c - 'A'));
        int ans = -1;
        if('a' <= c && c <= 'c')
            ans = 2;
        else if('d' <= c && c <= 'f')
            ans = 3;
        else if('g' <= c && c <= 'i')
            ans = 4;
        else if('j' <= c && c <= 'l')
            ans = 5;
        else if('m' <= c && c <= 'o')
            ans = 6;
        else if('p' <= c && c <= 's')
            ans = 7;
        else if('t' <= c && c <= 'v')
            ans = 8;
        else if('w' <= c && c <= 'z')
            ans = 9;
        else
            ans = -1;
        if(ans != -1)
            System.out.println("The corresponding number is " + ans);
        else
            System.out.println(c + " is an invalid input");
    }
}

