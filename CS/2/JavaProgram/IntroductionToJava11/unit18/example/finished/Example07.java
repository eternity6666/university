// DirectorySize.java

package unit18.example.out;

import java.io.File;
import java.util.Scanner;

public class Example07 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a directory or a file: ");
        String directory = input.nextLine();

        System.out.println(getSize(new File(directory)) + " bytes");
    }

    public static long getSize(File file) {
        long size = 0;
        if(file.isDirectory()) {
            File[] files = file.listFiles();
            for(int i = 0; files != null && i < files.length; i++) {
                size += getSize(files[i]);
            }
        }
        else {
            size += file.length();
        }

        return size;
    }
}

