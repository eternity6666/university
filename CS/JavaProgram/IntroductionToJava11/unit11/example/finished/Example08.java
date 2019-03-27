// TestArrayList;
package unit11.example.out;

import java.util.ArrayList;
import unit11.example.out.Example02;

public class Example08 {
    public static void main(String[] args) {

        ArrayList<String> cityList = new ArrayList<>();

        cityList.add("London"); 
        cityList.add("Denver");
        cityList.add("Paris");
        cityList.add("Beijing");
        cityList.add("Miami");
        cityList.add("Wuhang");

        System.out.println(cityList.toString());
        System.out.println("List size? " + cityList.size());
        System.out.println("Is Miami in the list? " + cityList.contains("Miami"));
        System.out.println("Is location of Denver in the list? " + cityList.indexOf("Denver"));
        System.out.println("Is the list empty? " + cityList.isEmpty());

        cityList.add(2, "Xian");
        cityList.remove("Miami");
        cityList.remove(1);

        System.out.println(cityList.toString());

        for(int i = cityList.size() - 1; i >= 0; i--) {
            System.out.print(cityList.get(i) + " ");
        }
        System.out.println();

        ArrayList<Example02> list = new ArrayList<>();

        Example02 tmp = new Example02(2);
        list.add(tmp);
        tmp = new Example02(3);
        list.add(tmp);
        System.out.println(1);
        
        System.out.println("The area of the circle? " + list.get(0).getArea());
    }
}

