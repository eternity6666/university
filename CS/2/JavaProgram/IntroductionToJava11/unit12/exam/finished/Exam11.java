package unit12.exam.out;

import java.io.*;
import java.util.*;

public class Exam11 {
    public static void main(String[] args) throws Exception{
        if(args.length != 2) {
            System.out.println("Usage: java Exam11 deleteString filename");
            System.exit(1);
        }

        File sourceFile = new File(args[1]);
        if(!sourceFile.exists()) {
            System.out.println("Source file " + args[1] + " does not exist");
            System.exit(2);
        }

        File tmpFile = new File(args[1] + "tmp");
        if(tmpFile.exists()) {
            System.out.println("Tmp file " + args[1] + "tmp already exists");
            System.exit(3);
        }

        try (
                Scanner input = new Scanner(sourceFile);
                PrintWriter output = new PrintWriter(tmpFile);
        ) {
            while(input.hasNext()) {
                String s1 = input.nextLine();
                String s2 = s1.replaceAll(args[0], "");
                s2 = s2.replaceAll("  ", "");
                output.println(s2);
            }
        }

        if(!sourceFile.delete()) {
            System.out.println("Can't delete " + args[1]);
            System.exit(4);
        }
        System.out.println("Already delete " + args[1]);
        if(!tmpFile.renameTo(sourceFile)) {
            System.out.println("Can't rename " + args[1] + "tmp");
            System.exit(4);
        }
        System.out.println("Already rename " + args[1] + "tmp to " + args[1]);
    }
}

