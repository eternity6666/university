package unit07.exam.out;

import java.util.Scanner;

public class Exam15 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter ten numbers: ");
        int[] list = new int[10];
        for(int i = 0; i < 10; i++)
            list[i] = input.nextInt();

        System.out.print("The distinct numbers are: ");
        int[] ans = eliminateDuplicates(list);
        for(int i = 0; i < ans.length; i++)
            System.out.print(ans[i] + " ");
        System.out.println();
    }

    public static int[] eliminateDuplicates(int[] list) {
        int[] tmp = new int[list.length];
        int len = 0;
        for(int i = 0; i < list.length; i++) {
            boolean flag = true;
            for(int j = 0; j < len; j++)
                if(tmp[j] == list[i]) {
                    flag = false;
                    break;
                }
            if(flag)
                tmp[len++] = list[i];
        }

        int[] ans = new int[len];
        for(int i = 0; i < len; i++)
            ans[i] = tmp[i];

        return ans;
    }
}

