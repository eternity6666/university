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
                    if(s.charAt(0) == '-')
                        System.out.print(s + "的小数部分为: -0.");
                    else
                        System.out.print(s + "的小数部分为: 0.");
                    for(int i = x + 1; i < s.length(); i++)
                        System.out.print(s.charAt(i));
                    System.out.println();
                }
            }
            else
                System.out.println("输入浮点数格式有误");
        }
    }
}

