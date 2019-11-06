// DetectEndOfFile.java

package unit17.example.out;

import java.io.*;

public class Example03 {

    public static void main(String[] args) {
        try {
            try (
                DataOutputStream output = new DataOutputStream(new FileOutputStream("test.dat"));
            ) {
                output.writeDouble(4.5);
                output.writeDouble(43.25);
                output.writeDouble(3.35);
            }

            try (
                DataInputStream input = new DataInputStream(new FileInputStream("test.dat"));
            ) {
                while(true)
                    System.out.println(input.readDouble());
            }
        }
        catch (EOFException ex) {
            System.out.println("All data were read");
        }
        catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}

