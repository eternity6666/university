public class example02 {

    public static void main(String[] args) {

        example02 circle1 = new example02();
        System.out.println("The area of the circle of radius " + circle1.radius + " is " + circle1.getArea());

        example02 circle2 = new example02(25);
        System.out.println("The area of the circle of radius " + circle2.radius + " is " + circle2.getArea());

        example02 circle3 = new example02(125);
        System.out.println("The area of the circle of radius " + circle3.radius + " is " + circle3.getArea());

        circle2.radius = 100;
        System.out.println("The area of the circle of radius " + circle2.radius + " is " + circle2.getArea());


    }

    double radius;

    example02() {
        radius = 1;
    }

    example02(double newRadius) {
        radius = newRadius;
    }

    double getArea() {
        return radius * radius * Math.PI;
    }

    double getPerimeter() {
        return 2 * radius * Math.PI;
    }

    void setRadius(double newRadius) {
        radius = newRadius;
    }
}


