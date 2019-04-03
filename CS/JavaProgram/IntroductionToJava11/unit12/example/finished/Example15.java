// ReadData.java

package unit12.example.out;

import java.util.Scanner;
import java.io.File;

public class Example15 {
    public static void main(String[] args) throws Exception {

        File file = new File("scores.txt");

        Scanner input = new Scanner(file);

        while (input.hasNext()) {
            String firstName = input.next();
            String mi = input.next();
            String lastName = input.next();
            int score = input.nextInt();
            System.out.println(firstName + " " + mi + " " + lastName + " " + score);
        }

        input.close();
    }
}

