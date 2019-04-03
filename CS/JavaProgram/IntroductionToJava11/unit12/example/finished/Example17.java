// ReadFileFromURL.java

package unit12.example.out;

import java.util.Scanner;
import java.net.*;
import java.io.*;

public class Example17 {
    public static void main(String[] args) {
        System.out.print("Enter a URL: ");
        String URLString = new Scanner(System.in).next();

        try {
            URL url = new URL(URLString);
            int count = 0;
            Scanner input = new Scanner(url.openStream());
            while(input.hasNext()) {
                String line = input.nextLine();
                System.out.println(line);
                count += line.length();
            }

            System.out.println("The file size is " + count + " characters");
        }
        catch(MalformedURLException ex) {
            System.out.println("Invalid URL");
        }
        catch(IOException ex) {
            System.out.println("I/O Errors: no such file");
        }
    }
}


