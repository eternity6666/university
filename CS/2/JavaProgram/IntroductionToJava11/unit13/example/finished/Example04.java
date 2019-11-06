// TestGeometricObject.java

package unit13.example.out;

import unit13.example.out.*;

public class Example04 {
    public static void main(String[] args) {
        Example01 geoObject1 = new Example02(5);
        Example01 geoObject2 = new Example03(4,3);

        System.out.println("The two objects have the same area? " + equalArea(geoObject1, geoObject2));

        displayGeometricObject(geoObject1);
        
        displayGeometricObject(geoObject2);
    }

    public static boolean equalArea(Example01 object1, Example01 object2) {
        return object1.getArea() == object2.getArea();
    }

    public static void displayGeometricObject(Example01 object) {
        System.out.println();
        System.out.println("The area is " + object.getArea());
        System.out.println("The perimeter is " + object.getPerimeter());
    }
}

