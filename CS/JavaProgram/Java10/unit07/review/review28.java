import java.util.Arrays;

public class review28{

    public static void main(String[] args){

        int[] list1 = {2, 4, 7, 10};

        Arrays.fill(list1, 7);
        System.out.println(Arrays.toString(list1));
        
        int[] list2 = {2, 4, 7, 10};
        System.out.println(Arrays.toString(list2));
        System.out.println(Arrays.equals(list1, list2));
    }
}

