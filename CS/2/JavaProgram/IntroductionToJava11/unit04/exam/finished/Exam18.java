package unit04.exam.out;

import java.util.Scanner;
import java.lang.Character;

public class Exam18 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter two characters: ");
        char a, b;
        String s = input.next();
        if(s.length() >= 2) {
            a = s.charAt(0);
            b = s.charAt(1);
            if('1' <= b && b <= '4' && (a == 'm' || a == 'M' || a == 'C' || a == 'c' || a == 'i' || a == 'I')) {
                if('a' <= a && a <= 'z')
                    a = Character.toUpperCase(a);
                String ans = "";
                switch(a) {
                    case 'M':
                        ans = "Mathematics ";
                        break;
                    case 'C':
                        ans = "Computer Science ";
                        break;
                    case 'I':
                        ans = "Information Technology ";
                        break;
                    default:
                        ans = "Invalid";
                        break;
                }
                switch(b) {
                    case '1':
                        ans += "Freshman";
                        break;
                    case '2':
                        ans += "Sophomore";
                        break;
                    case '3':
                        ans += "Junior";
                        break;
                    case '4':
                        ans += "Senior";
                        break;
                    default:
                        ans = "Invalid";
                }
                if(ans.equals("Invalid")) {
                    System.out.println("Invalid input"); 
                }
                else
                    System.out.println(ans);
            }
            else
                System.out.println("Invalid input");
        }
        else {
            System.out.println("Input Error");
            System.exit(1);
        }
    }
}

