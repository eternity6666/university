package unit12.exam.out;

import java.util.Scanner;
import java.io.File;
import java.io.PrintWriter;

public class Exam24 {
    public static void main(String[] args) throws Exception{
        File file = new File("Salary.txt");
        try (
            PrintWriter output = new PrintWriter(file);
        ) {
            for(int i = 1; i <= 1000; i++) {
                String tmp = "FirstName" + i + " LastName" + i;
                int className = (int)(Math.random() * 3);
                int money;
                switch(className) {
                    case 0:
                        tmp = tmp + " assistant ";
                        money = (int)(Math.random() * 30000 + 1) + 50000;
                        break;
                    case 1:
                        tmp = tmp + " associate ";
                        money = (int)(Math.random() * 50000 + 1) + 60000;
                        break;
                    case 2:
                        tmp = tmp + " full ";
                        money = (int)(Math.random() * 55000 + 1) + 75000;
                        break;
                    default:
                        money = 1;
                        break;
                }
                tmp = tmp + money;
                output.println(tmp);
            }
        }
    }
}

