import java.util.Scanner;
import java.util.ArrayList;

public class Exam1109 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the array size n: ");
        int n = input.nextInt();

        int[][] array = new int[n][n];
        ArrayList<Integer> row = new ArrayList<>();
        ArrayList<Integer> column = new ArrayList<>();

        System.out.println("The random array is");
        int tmp = -1;
        for(int i = 0; i < array.length; i++) {
            int count = 0;
            for(int j = 0; j < array[i].length; j++) {
                array[i][j] = (int)(Math.random() * 100) % 2;
                System.out.print(array[i][j]);
                if(array[i][j] == 1)
                    count++;
            }
            System.out.println();
            if(count > tmp) {
                tmp = count;
                row.clear();
                row.add(i);
            }
            else if(count == tmp)
                row.add(i);
        }

        if(row.isEmpty())
            System.out.println("The random array doesn't have number 1");
        else {
            System.out.print("The largest row index:");
            for(int i = 0; i < row.size(); i++)
                System.out.print(" " + row.get(i));
            System.out.println();
            
            tmp = -1;
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int i = 0; i < n; i++) {
                    if(array[i][j] == 1)
                        count++; 
                }
                if(count > tmp) {
                    tmp = count;
                    column.clear();
                    column.add(j);
                }
                else if(count == tmp)
                    column.add(j); 
            }
            System.out.print("The largest column index:");
            for(int i = 0; i < column.size(); i++)
                System.out.print(" " + column.get(i));
            System.out.println(); 

        }
    }
}

