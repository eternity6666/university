package unit14.example.out;

import javafx.scene.text.Font;
import java.util.*;

public class Test08 {
    public static void main(String[] args) {
        List<String> list = Font.getFamilies();
        int len = list.size();
        for(int i = 0; i < len; i++) {
            System.out.print(list.get(i) + "; ");
            if((i + 1) % 3 == 0)
                System.out.println();
        }
    }
}

