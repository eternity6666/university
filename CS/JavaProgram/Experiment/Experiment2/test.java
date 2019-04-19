import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int count = 0;
        while(true) {
            if(count++ == 5)
                break;
            System.out.println("请输入一个浮点数: ");
            System.out.print("  ");
            String s = input.next();
            if(s.matches("^(\\-|\\+)?\\d+(\\.\\d+)?$")) {
                int x = -1;
                for(int i = 0; i < s.length(); i++) 
                    if(s.charAt(i) == '.') {
                        x = i;
                        break;
                    }
                if(x == -1) {
                    System.out.print(s + "的整数部分为: ");
                    boolean tmp0 = false;
                    for(int i = 0; i < s.length(); i++)
                        if(tmp0)
                            System.out.print(s.charAt(i));
                        else {
                            if(s.charAt(i) == '-')
                                System.out.print('-');
                            else if(s.charAt(i) != '0') {
                                tmp0 = true;
                                System.out.print(s.charAt(i));
                            }
                        }
                    if(tmp0 == false)
                        System.out.print(0);
                    System.out.println();

                    if(s.charAt(0) == '-')
                        System.out.print(s + "的小数部分为: -0.0");
                    else
                        System.out.print(s + "的小数部分为: 0.0");
                }
                else {
                    System.out.print(s + "的整数部分为: ");
                    boolean tmp0 = false;
                    for(int i = 0; i < x; i++)
                        if(tmp0)
                            System.out.print(s.charAt(i));
                        else {
                            if(s.charAt(i) == '-')
                                System.out.print('-');
                            else if(s.charAt(i) != '0') {
                                tmp0 = true;
                                System.out.print(s.charAt(i));
                            }
                        }
                    System.out.println();
                    /*
                    for(int i = 0; i < x; i++)
                        System.out.print(s.charAt(i));
                    */

                    if(s.charAt(0) == '-')
                        System.out.print(s + "的小数部分为: -0.");
                    else
                        System.out.print(s + "的小数部分为: 0.");
                    for(int i = x + 1; i < s.length(); i++)
                        System.out.print(s.charAt(i));
                    System.out.println();
                }
                /*
                double x = 0.0;
                boolean flag = false;
                double tmp = 0.1;
                for (int i = 0; i < s.length(); i++) {
                    if(flag) {
                        x = x + (s.charAt(i) - '0') * tmp;
                        tmp /= 10;
                    }
                    else {
                        if(s.charAt(i) == '.')
                            flag = true;
                        else {
                            x = x * 10 + (s.charAt(i) - '0');
                        }
                    }
                }
                int tmp1 = (int)x;
                double tmp2 = x - tmp1;
                System.out.println(x + "的整数部分为: " + tmp1);
                System.out.println(x + "的小数部分为: " + tmp2);
                */
            }
            else
                System.out.println("输入浮点数格式有误");
        }
    }
}

