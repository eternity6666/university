import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfInts = scanner.nextInt();
        ArrayList<Integer> integers = new ArrayList<>();
        for (int i = 0; i < numOfInts; i++)
            integers.add(scanner.nextInt());
        int max = getMax(integers);
        System.out.print(max + " ");
        integers.remove(integers.indexOf(max));
        max = getMax(integers);
        System.out.println(max);
        int min = getMin(integers);
        System.out.print(min + " ");
        integers.remove(integers.indexOf(min));
        min = getMin(integers);
        System.out.println(min);

     }

    static int getMax(List<Integer> list) {
        if (list.size() == 1)
            return list.get(0);
        if (list.size() == 2)
            return Math.max(list.get(0), list.get(1));
        int int1 = getMax(list.subList(0, list.size() / 2));
        int int2 = getMax(list.subList(list.size() / 2, list.size()));
        return Math.max(int1, int2);
    }

    static int getMin(List<Integer> list) {
        if (list.size() == 1)
            return list.get(0);
        if (list.size() == 2)
            return Math.min(list.get(0), list.get(1));
        int int1 = getMin(list.subList(0, list.size() / 2));
        int int2 = getMin(list.subList(list.size() / 2, list.size()));
        return Math.min(int1, int2);
    }
}