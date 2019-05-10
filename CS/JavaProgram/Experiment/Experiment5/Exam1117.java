import java.util.Scanner;

public class Exam1117 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter an integer m: ");
        int m = input.nextInt();

        int[] list = new int[(int)Math.sqrt(m) + 1];
        for(int i = 0; i < list.length; i++)
            list[i] = 0;

        int n = 1;
        for(int i = 2; i <= Math.sqrt(m); i++) {
            if(m % i == 0) 
                if(isOdd(m, i))
                    if(isPrime(i))
                        n *= i;
        }
        System.out.println("The smallest number n for m * n to be a perfect square is " + n);
        System.out.println("m * n is " + (m * n));
    }

    public static boolean isOdd(int m, int x) {
        int n = 0;
        while(m % x == 0) {
            n++;
            m /= x;
        }
        // System.out.println(x + " " + n);
        return n % 2 == 1;
    }

    public static boolean isPrime(int x) {
        for(int i = 2; i <= Math.sqrt(x); i++)
            if(x % i == 0)
                return false;
        // System.out.println(x);
        return true;
    }
}

