package unit05.exam.out;

import java.util.Scanner;

public class Exam17{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of lines: ");
        
        int lines = input.nextInt();

        for(int i = 1; i <= lines; i++){
            for(int j = 1; j <= lines - i; j++){
                outOfSpace(getDigit(lines));
                System.out.print(" ");
            }
            for(int j = i; j > 1; j--){
                outOfSpace(getDigit(lines) - getDigit(j));
                System.out.print(" " + j);
            }
            for(int j = 1; j <= i; j++){
                outOfSpace(getDigit(lines) - getDigit(j));
                System.out.print(" " + j);
            }
            System.out.println();
        }
    }

    public static int getDigit(int x){

        int ans = 1;
        while(x / 10 != 0){

            ans++;
            x /= 10;
        }
        return ans;
    }
    public static void outOfSpace(int x){
        while(x != 0)
        {
            x--;
            System.out.print(" ");
        }
        /*
        while(x / 10 != 0){
            System.out.print(" ");
            x /= 10;
        }
        */
    }
}

