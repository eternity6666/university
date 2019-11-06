// TestObjectOutputStream.java

package unit17.example.out;

import java.io.*;

public class Example05 {
    
    public static void main(String[] args) throws IOException {
        try (
            ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream("object.dat"));
        ) {
            output.writeUTF("John");
            output.writeDouble(85.5);
            output.writeObject(new java.util.Date());
        }
    }
}

