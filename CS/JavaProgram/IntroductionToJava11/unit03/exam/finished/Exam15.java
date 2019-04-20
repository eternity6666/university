package unit03.exam.out;

import java.util.Scanner;

public class Exam15 {

    public static void main(String[] args) {
        int x = (int)(Math.random() * 900 + 100);
        int b, s, g;
        b = x / 100;
        s = x / 10 % 10;
        g = x % 10;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int user = input.nextInt();
        int userb, users, userg;
        userb = user / 100;
        users = user / 10 % 10;
        userg = user % 10;
        System.out.print("The random number is " + x + " and you win ");
        if(user == x)
            System.out.println(10000);
        else {
            int tmp = 0;
            if(b == userb)
                tmp++;
            else if(b == users)
                tmp++;
            else if(b == userg)
                tmp++;
            if(s == userb)
                tmp++;
            else if(s == users)
                tmp++;
            else if(s == userg)
                tmp++;
            if(g == userb)
                tmp++;
            else if(g == users)
                tmp++;
            else if(g == userg)
                tmp++;
            if(tmp == 0)
                System.out.println(0);
            else if(tmp < 3)
                System.out.println(1000);
            else
                System.out.println(3000);
        }
    }
}

    /*
    public void main(String[] args) {
        int x = (int)(Math.random() * 900 + 100);
        String s = getString(x);
        Scanner input = new Scanner(System.in);
        int in = input.nextInt();
        String b = getString(in);
        int money = 0;
        if(b.equals(s))
            money = 10000;
        else {
            // boolean flag = true;
            int y = 0;
            for(int i = 0; i < s.length(); i++)
                if(b.contains(s.charAt(i))) {
                    y++;
                }
            if(y == 3)
                money = 3000;
            else if(y > 0)
                money = 1000;
            else
                money = 0;
        }
        System.out.println("The random number is " + x);
        System.out.println("You win " + money + " dollars.");
    }

    public String getString(int x) {
        String s = "";
        while(x % 10 != 0) {
            s = s + ('0' + x % 10);
            x /= 10;
        }
        return s;
    }
    */

