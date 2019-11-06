import java.util.*;

public class exam30{

    public static void main(String[] args){

        // Scanner input = new Scanner(System.in);
        
        int x = 0;
        for(int i = 1; i <= 5; i++)
        {
            System.out.println("#" + i);
            int number1 = crap();
            int number2 = crap();

            rolled(number1, number2);
            int sum = number1 + number2;

            if(sum == 7 || sum == 11){
                System.out.println("You win.");
                x++;
            }
            else if(sum == 2 || sum == 3 || sum == 12)
                System.out.println("You lose.");
            else{
                System.out.println("Point is " + (number1 + number2));
                do{
                    number1 = crap();
                    number2 = crap();
                    rolled(number1, number2);
                    if(number1 + number2 == sum){
                        x++;
                        System.out.println("You win.");
                        break;
                    }
                    else if(number1 + number2 == 7){
                        System.out.println("You lose.");
                        break;
                    }
                    else{
                        System.out.println("Point is " + (number1 + number2));
                    }
                }while(true);
            }
        }
        System.out.println("You win " + x + " times.");
    }

    public static void rolled(int a, int b){

        System.out.println("You rolled " + a + " + " + b + " = " + (a + b));
    }

    public static int crap(){
        return (int)(Math.random() * 6 + 1);
    }
}

