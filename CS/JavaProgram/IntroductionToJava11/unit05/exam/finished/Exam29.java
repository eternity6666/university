package unit05.exam.out;

import java.util.Scanner;

public class Exam29 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter year: ");
        int year = input.nextInt();
        System.out.print("Enter the day of the first day in " + year + ": ");
        int day = input.nextInt();
        int dayx = day % 7;
        String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int[] dayOfMonth = new int[12];
        for(int i = 1; i <= 12; i++) {
            if(i == 2) 
                if(leapYear(year))
                    dayOfMonth[i - 1] = 29;
                else
                    dayOfMonth[i - 1] = 28;
            else if(i <= 7)
                if(i % 2 == 0)
                    dayOfMonth[i - 1] = 30;
                else
                    dayOfMonth[i - 1] = 31;
            else
                if(i % 2 == 0)
                    dayOfMonth[i - 1] = 31;
                else
                    dayOfMonth[i - 1] = 30;
            String s = months[i - 1] + " " + year;
            int x = 45 - s.length();
            x /= 2;
            for(int j = 0; j < x; j++)
                System.out.print(' ');
            System.out.println(s);
            for(int j = 0; j < 45; j++)
                System.out.print('_');
            System.out.println();
          System.out.println("Sun    Mon    Tue    Wed    Thu    Fri    Sat");
            for(int j = 1; j <= dayOfMonth[i - 1]; j++) {
                if(j == 1) {
                    int tmp = dayx % 7;
                    for(int k = 0; k < tmp; k++)
                        System.out.print("       ");
                }
                if((j + dayx) % 7 == 0)
                    if(j <= 9)
                        System.out.println(" " + j + " ");
                    else
                        System.out.println(j + " ");
                else
                    if(j <= 9)
                        System.out.print(" " + j + "     ");
                    else if(j == dayOfMonth[i - 1])
                        System.out.println(j + "     ");
                    else
                        System.out.print(j + "     ");
            }
            System.out.println();
            dayx = dayx + dayOfMonth[i - 1];
            dayx = dayx % 7;
        }
    }

    public static boolean leapYear(int year) {
        if(year % 4 == 0)
            if(year % 400 == 0)
                return true;
            else if(year % 100 == 0)
                return false;
            else
                return true;
        else
            return false;
    }
}

