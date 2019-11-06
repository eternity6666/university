package unit04.exam.out;

import java.util.Scanner;

public class Exam17 {

    public static boolean leap(int year) {
        if(year % 4 == 0) {
            if(year % 400 == 0)
                return true;
            else if(year % 100 == 0)
                return false;
            else
                return true;
        }
        else
            return false;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a year: ");
        int year = input.nextInt();
        System.out.print("Enter a month: ");
        String month = input.next();
        int day = 0;
        if(month.equals("Feb"))
            if(leap(year))
                day = 29;
            else
                day = 28;
        else {
            if(month.equals("Jan") || month.equals("Mar") || month.equals("May"))
                day = 31;
            else if(month.equals("Jul") || month.equals("Aug") || month.equals("Oct") || month.equals("Dec"))
                day = 31;
            else
                day = 30;
        }
        System.out.println(month + " " + year + " has " + day + " days");
    }

}


