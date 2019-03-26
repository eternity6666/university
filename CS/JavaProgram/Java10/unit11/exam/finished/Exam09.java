package unit11.exam.out;

import java.util.Scanner;
import java.util.ArrayList;

public class Exam09 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the array size n: ");
        int n = input.nextInt();

        ArrayList<Integer> row = new ArrayList<>();
        ArrayList<Integer> col = new ArrayList<>();
        int maxRow;
        int maxCol;
        maxRow = maxCol = 0;

        int[][] arrays = new int[n][n];
        System.out.println("The random array is");
        for(int i = 0; i < arrays.length; i++) {
            int tmpRow = 0;
            for(int j = 0; j < arrays[i].length; j++) {
                int tmp = (int)(Math.random() * 100);
                arrays[i][j] = tmp % 2;
                System.out.print(arrays[i][j]);
                if(arrays[i][j] == 1)
                    tmpRow++;
            }
            System.out.println();
            if(tmpRow > maxRow) {
                maxRow = tmpRow;
                row.clear();
                row.add(i);
            }
            else if(tmpRow == maxRow)
                row.add(i);
        }
        for(int j = 0; j < arrays[0].length; j++) {
            int tmpCol = 0;
            for(int i = 0; i < arrays.length; i++) {
                if(arrays[i][j] == 1) {
                    tmpCol++;
                }
            }
            if(tmpCol > maxCol)
            {
                maxCol = tmpCol;
                col.clear();
                col.add(j);
            }
            else if(tmpCol == maxCol)
                col.add(j);
        }
        System.out.println("The largest row index: " + row.toString());
        System.out.println("The largest col index: " + col.toString());
    }
}

