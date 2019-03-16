import java.util.Scanner;

public class exam13{

    public static void main(String[] args){
        Scanner inner = new Scanner(System.in);

        System.out.print("Enter the monthly saving amount: ");
        double x = inner.nextDouble();
        double ans = 0;
        for(int i = 1; i <= 6; i++){
            ans = (ans + x) * (1 + 0.00417);
        }
        System.out.println("After the sixth month, the account value is $" + ans);
        System.out.printf("After the sixth month, the account value is $%.2f\n", ans);
    }
}
