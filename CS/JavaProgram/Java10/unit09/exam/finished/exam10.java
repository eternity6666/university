import java.util.*;

public class exam10 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of a: ");
        double a = input.nextDouble();
        System.out.print("Enter the number of b: ");
        double b = input.nextDouble();
        System.out.print("Enter the number of c: ");
        double c = input.nextDouble();
        QuadraticEquation eq = new QuadraticEquation(a, b, c);
        if(eq.getDiscriminant() < 0)
            System.out.println("The equation has no roots.");
        else if(eq.getDiscriminant() == 0)
            System.out.println("The equation has one root: " + eq.getRoot1());
        else
            System.out.println("The equation has two different roots: " + eq.getRoot1() + " and " + eq.getRoot2());
    }
}

class QuadraticEquation {

    private double a, b, c;

    public QuadraticEquation(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double getDiscriminant() {
        return b * b - 4 * a * c;
    }

    public double getRoot1() {
        return ( -b + Math.sqrt(getDiscriminant())) / (2 * a);
    }

    public double getRoot2() {
        return ( -b - Math.sqrt(getDiscriminant())) / (2 * a);
    }
}

