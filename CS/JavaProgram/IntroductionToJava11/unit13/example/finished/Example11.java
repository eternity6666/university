// House.java

package unit13.example.out;

public class Example11 implements Cloneable, Comparable<Example11> {
    private int id;
    private double area;
    private java.util.Date whenBuilt;

    public Example11(int id, double area) {
        this.id = id;
        this.area = area;
        whenBuilt = new java.util.Date();
    }

    public int getId() {
        return id;
    }

    public double getArea() {
        return area;
    }

    public java.util.Date getWhenBuilt() {
        return whenBuilt;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    @Override
    public int compareTo(Example11 o) {
        if(area > o.area)
            return 1;
        else if(area < o.area)
            return -1;
        else
            return 0;
    }
}

