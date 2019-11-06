package unit03.review.out;

import java.util.*;

public class review36{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        for(int i = 1; i <= 100; i++)
        {
            System.out.print("#" + i + ": ");
            int x = (int)(Math.random() * 100);

            System.out.println(x % 2 == 0 ? 1 : -1);
        }
    }
}

