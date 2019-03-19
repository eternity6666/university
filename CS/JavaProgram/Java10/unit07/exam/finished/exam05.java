import java.util.Scanner;
import java.util.Arrays;

public class exam05{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        System.out.print("Enter ten numbers: ");
        int numbers[] = new int[11];

        int x = 0;
        for(int i = 0; i < 10; i++){
            numbers[i] = input.nextInt();
            boolean flag = false;
            for(int j = 0; j < i; j++){
                if(numbers[i] == numbers[j]){
                    flag = true;
                    // x++;
                    break;
                }
            }
            if(!flag)
                x++;
        }

        System.out.println("The number of distinct number is " + x);
        System.out.print("The distinct numbers are: ");
        for(int i = 0; i < 10; i++){
            boolean flag = false;
            for(int j = 0; j < i; j++){
                if(numbers[i] == numbers[j]){
                    flag = true;
                    // x++;
                    break;
                }
            }
            if(!flag){
                if(i != 0)
                    System.out.print(" ");
                System.out.print(numbers[i]);
            }
        }
        System.out.println();
    }
}

