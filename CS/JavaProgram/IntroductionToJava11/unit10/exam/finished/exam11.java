package unit10.exam.out;

public class exam11 {

    public static void main(String[] args) {
        Circle2D c1 = new Circle2D(2, 2, 5.5);

        System.out.println("The c1 is " + c1.toString());
        System.out.println();

        System.out.println("The area of c1 is " + c1.getArea());
        System.out.println("The perimeter of c1 is " + c1.getPerimeter());
        System.out.println();

        if(c1.contains(3, 3))
            System.out.println("The c1(2, 2, 5.5) contains point(3, 3)");
        else
            System.out.println("The c1(2, 2, 5.5) doesn't contain point(3, 3)");
        System.out.println();

        if(c1.contains(new Circle2D(4, 5, 10.5)))
            System.out.println("The c1(2, 2, 5.5) contains circle(4, 5, 10.5)");
        else
            System.out.println("The c1(2, 2, 5.5) doesn't contain circle(4, 5, 10.5)");
        System.out.println();

        
        if(c1.overlaps(new Circle2D(4, 5, 10.5)))
            System.out.println("The c1(2, 2, 5.5) overlaps circle(3, 5, 2.3)");
        else
            System.out.println("The c1(2, 2, 5.5) doesn't overlap circle(3, 5, 2.3)");
        System.out.println();

    }
}

class Circle2D {
    private double x;
    private double y;
    private double radius;

    public Circle2D() {
        this(0, 0, 1);
    }

    public Circle2D(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    double getX() {
        return this.x;
    }

    double getY() {
        return this.y;
    }

    double getRadius() {
        return this.radius;
    }

    double getArea() {
        return this.radius * this.radius * Math.PI;
    }

    double getPerimeter() {
        return this.radius * 2 * Math.PI;
    }

    boolean contains(double x, double y) {
        double d = Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2);
        return d < this.radius * this.radius;
    }

    boolean contains(Circle2D circle) {
        double d = Math.pow(this.x - circle.x, 2) + Math.pow(this.y - circle.y, 2);
        return Math.sqrt(d) + circle.radius < this.radius;
    }

    boolean overlaps(Circle2D circle) {
        double d = Math.pow(this.x - circle.x, 2) + Math.pow(this.y - circle.y, 2);
        return this.radius + circle.radius > Math.sqrt(d);
    }

    @Override
    public String toString() {
        return "x: " + x + " y: " + y + " radius: " + radius;
    }
}

