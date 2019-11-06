package unit09.exam.out;

public class Exam09{
    public static void main(String[] args) {
        RegularPolygon a = new RegularPolygon();
        RegularPolygon b = new RegularPolygon(6, 4);
        RegularPolygon c = new RegularPolygon(10, 4, 5.6, 7.8);

        System.out.println("a:\n\tPerimeter=" + a.getPerimeter() + "\n\tArea=" + a.getArea());
        System.out.println("b:\n\tPerimeter=" + b.getPerimeter() + "\n\tArea=" + b.getArea());
        System.out.println("c:\n\tPerimeter=" + c.getPerimeter() + "\n\tArea=" + c.getArea());
    }
}

class RegularPolygon{
    private int n = 3;
    private double side = 1;
    private double x = 0;
    private double y = 0;

    public RegularPolygon(){
        this(3, 1, 0, 0);
    }

    public RegularPolygon(int n, double side) {
        this(n, side, 0, 0);    
    }

    public RegularPolygon(int n, double side, double x, double y) {
        this.n = n;
        this.side = side;
        this.x = x;
        this.y = y;
    }

    public double getSide() {
        return this.side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    public int getN() {
        return this.n;
    }

    public void setN(int n) {
        this.n = n;
    }

    public double getX() {
        return this.x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return this.y;
    }

    public void setY(double y) {
        this.y = y;
    }
    
    public double getPerimeter() {
        return n * side;
    }

    public double getArea() {
        return n * side * side / (4 * Math.tan(Math.PI / n));
    }
}

