package unit07.example.out;

public class Example05{

    public static void main(String[] args){
        printMax(34, 5, 10, 30, 323, 100, 55.32);
        printMax(new double[]{1, 2, 3, 10, 100, -12, 78});
    }

    public static void printMax(double... numbers){

        int len = numbers.length;
        if(len == 0){
            System.out.println("No argument passed");
            return ;
        }

        double result = numbers[0];
        for(int i = 1; i < len; i++){
            if(numbers[i] > result)
                result = numbers[i];
        }

        System.out.println("The max value is " + result);
    }
}

