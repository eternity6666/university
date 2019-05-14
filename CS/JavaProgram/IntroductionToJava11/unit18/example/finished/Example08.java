// TowerOfHanoi.java

package unit18.example.out;

import java.util.Scanner;
public class Example08 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of disks: ");
        int n = input.nextInt();

        System.out.println("The moves are: ");
        moveDisk(n, 'A', 'B', 'C');
    }

    public static void moveDisk(int n, char fromTower, char toTower, char auxTower) {
        if(n == 1)
            System.out.println("Move disk " + n + " from " + fromTower + " to " + toTower);
        else {
            moveDisk(n - 1, fromTower, auxTower, toTower);
            System.out.println("Move disk " + n + " from " + fromTower + " to " + toTower);
            moveDisk(n - 1, auxTower, toTower, fromTower);
        }
    }
}

