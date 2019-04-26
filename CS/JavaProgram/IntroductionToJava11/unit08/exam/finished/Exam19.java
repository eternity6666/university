// package unit08.exam.out;

import java.util.Scanner;

public class Exam19 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        // while(true) {
        System.out.print("Enter row and columns of the arrays: ");
        int row = input.nextInt();
        int col = input.nextInt();
        System.out.println("Enter the arrays: ");
        int[][] arrays = new int[row][col];
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                arrays[i][j] = input.nextInt();
        System.out.println(isConsecutiveFour(arrays));
        // }
    }

    public static boolean isConsecutiveFour(int[][] values) {
        for(int i = 0; i < values.length; i++) {
            for(int j = 0; j < values[i].length; j++) {
                if(right(values, i, j) || down(values, i , j) || rightDown(values, i , j) || rightUp(values, i, j))
                    return true;
            }
        }
        return false;
    }

    public static boolean right(int[][] values, int i, int j) {
        if(j <= values[i].length - 4) {
            int tmp = values[i][j];
            for(int k = 0; k < 4; k++)
                if(tmp != values[i][j + k])
                    return false;
            return true;
        }
        return false;
    }

    public static boolean down(int[][] values, int i, int j) {
        if(i <= values[i].length - 4) {
            int tmp = values[i][j];
            for(int k = 0; k < 4; k++)
                if(tmp != values[i + k][j])
                    return false;
            return true;
        }
        return false;
    }

    public static boolean rightUp(int[][] values, int i, int j) {
        if(j <= values[i].length - 4 && i >= 3) {
            int tmp = values[i][j];
            for(int k = 0; k < 4; k++)
                if(tmp != values[i - k][j + k])
                    return false;
            return true;
        }
        return false;
    }

    public static boolean rightDown(int[][] values, int i, int j) {
        if(j <= values[i].length - 4 && i <= values[i].length - 4) {
            int tmp = values[i][j];
            for(int k = 0; k < 4; k++)
                if(tmp != values[i + k][j + k])
                    return false;
            return true;
        }
        return false;
    }

}

