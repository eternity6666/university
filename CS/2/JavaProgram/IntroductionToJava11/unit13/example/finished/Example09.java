// ComparableRectangle.java

package unit13.example.out;

import unit13.example.out.*;

public class Example09 extends Example03 implements Comparable<Example09> {
    public Example09(double width, double height) {
        super(width, height);
    }

    @Override
    public int compareTo(Example09 o) {
        if(getArea() > o.getArea())
            return 1;
        else if(getArea() < o.getArea())
            return -1;
        else
            return 0;
    }

    @Override
    public String toString() {
        return super.toString() + " Area: " + getArea();
    }
}

