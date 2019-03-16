import java.util.Scanner;

public class exam01{
    public static void main(String[] args){
        System.out.print("输入摄氏温度: ");
        Scanner inner = new Scanner(System.in);
        double ce = inner.nextDouble();

        double fa = ce * 9 / 5 + 32;
        System.out.println(ce + "摄氏度是 " + fa + " 华氏温度");
    }
}

