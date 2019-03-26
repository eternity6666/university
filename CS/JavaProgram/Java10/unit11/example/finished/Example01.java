// SimpleCeometricObject.java
package unit11.example.out;

public class Example01 {

    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    public Example01() {
        dateCreated = new java.util.Date();
    }

    public Example01(String color, boolean filled) {
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    /** Set a new color */
    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public java.util.Date getDateCreated() {
        return dateCreated;
    }

    public String toString() {
        return "created on " + dateCreated + "\ncolor: " + color + " and filled: " + filled;
    }
}

