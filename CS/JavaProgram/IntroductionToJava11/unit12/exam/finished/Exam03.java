// ArrayIndexOutBoundsException.java

package unit12.exam.out;

import java.util.Scanner;

public class Exam03 {
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        int[] arrays = new int[100];
        for(int i = 0; i < 100; i++)
            arrays[i] = (int)(Math.random() * 100 + 1);

        while(true) {
            System.out.print("Enter the index of Arrays(0-99): ");
            int x = input.nextInt();
            try {
                System.out.println("The " + x + " number is " + arrays[x]);
            }
            catch(Exception ex) {
                System.out.println("Out of Bounds");
            }
        }
    }
}

