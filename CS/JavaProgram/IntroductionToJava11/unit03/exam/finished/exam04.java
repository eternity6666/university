package unit03.exam.out;

import java.util.Scanner;

public class exam04{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        for(int i = 100; i > 0; i--)
        {
            int month = (int)(Math.random() * 12) + 1;        

            String ans;

            switch(month)
            {
                case 1:
                    ans = "January";
                    break;
                case 2:
                    ans = "February";
                    break;
                case 3:
                    ans = "March";
                    break;
                case 4:
                    ans = "April";
                    break;
                case 5:
                    ans = "May";
                    break;
                case 6:
                    ans = "June";
                    break;
                case 7:
                    ans = "July";
                    break;
                case 8:
                    ans = "August";
                    break;
                case 9:
                    ans = "September";
                    break;
                case 10:
                    ans = "October";
                    break;
                case 11:
                    ans = "November";
                    break;
                case 12:
                    ans = "December";
                    break;
                default:
                    ans = "**";
                    break;
            }
            System.out.println(ans);
        }
    }
}
