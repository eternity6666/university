package unit09.exam.out;

import unit09.exam.out.*;
import java.util.*;

public class Exam12{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double equa1[] = new double[4];
        System.out.print("Enter (x1, y1) and (x2, y2): ");
        for(int i = 0; i < 4; i++)
            equa1[i] = input.nextDouble();

        double equa2[] = new double[4];
        System.out.print("Enter (x3, y3) and (x4, y4): ");
        for(int i = 0; i < 4; i++)
            equa2[i] = input.nextDouble();

        LinearEquation a1 = new LinearEquation(equa1[0], 1, equa1[1], equa1[2], 1, equa1[3]);
        LinearEquation a2 = new LinearEquation(equa2[0], 1, equa2[1], equa2[2], 1, equa2[3]);
        boolean flag = false;
        if(a1.isSolvable())
            System.out.println(a1.getX() + " " + a1.getY());
        else {
            System.out.println("a1 error");
            flag = true;
        }
        if(a2.isSolvable())
            System.out.println(a2.getX() + " " + a2.getY());
        else {
            System.out.println("a2 error");
            flag = true;
        }
        LinearEquation ans = new LinearEquation(a1.getX(), -1, (-1) * a1.getY(), a2.getX(), -1, (-1) * a2.getY());

        if(ans.isSolvable())
            System.out.println("The point is (" + ans.getX() + ", " + ans.getY() + ")");
        else
            System.out.println("Don't have this point");
    }
}

