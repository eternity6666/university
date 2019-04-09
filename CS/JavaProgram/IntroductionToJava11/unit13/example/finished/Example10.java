// SortRectangle.java

package unit13.example.out;

import unit13.example.out.*;

public class Example10 {
    public static void main(String[] args) {
        Example09[] rectangles = {
            new Example09(3.4, 5.3),
            new Example09(13.23, 55.1),
            new Example09(89.0, 12.4),
            new Example09(1.4, 1234.1)};
        java.util.Arrays.sort(rectangles);
        for(Example09 rectangle: rectangles) {
            System.out.print(rectangle + " ");
            System.out.println();
        }
    }
}

