package unit12.exam.out;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Exam12 {
    public static void main(String[] args) throws Exception{
        if(args.length != 1) {
            System.out.println("Usage: java Exam12 filename");
            System.exit(1);
        }

        File file = new File(args[0]);
        if(!file.exists()) {
            System.out.println(args[0] + " does not exist.");
            System.exit(2);
        }

        String newFile = "";

        Scanner input = new Scanner(file);
        while(input.hasNext()) {
            String tmpNew = input.nextLine();
            System.out.println(tmpNew);
            if(tmpNew.contains("{")) {
                newFile = newFile + " {";
            }
            else
            { 
                if(newFile != "")
                    newFile = newFile + "\n" + tmpNew;
                else
                    newFile = tmpNew;
            }
        }
        
        if(!file.delete()) {
            System.out.println("Can't delete " + args[0]);
            System.exit(3);
        }
        System.out.println(args[0] + " already delete");
        try(
                PrintWriter output = new PrintWriter(file);
        )
        {
            output.println(newFile);
        }
    }
}

