import java.util.Scanner

public class input{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("请输入考试成绩: ");
        int score = input.nextInt();
        int count = 0;
        System.out.println("加分前的成绩: " + score);
        for(;score < 60; count++, score++);
        System.out.println("加分后的成绩: " + score);
        System.out.println("共加了" + count + "次! ");
    }
}

