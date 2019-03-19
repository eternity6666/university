import java.util.*;

public class exam35{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        while(true){

            System.out.print("Game Start? [Y/n]");
            String tmpYn = input.next();
            // char yn = input.next();
            char yn = tmpYn.charAt(0);
            if(yn != 'Y' && yn != 'y')
                break;
            String answer = creatWord();
            String sign = creatSign(answer.length()); 
            int missed = guessWord(answer, sign);
            System.out.println("The word is " + answer + ". ");
            if(missed > 1)
                System.out.println("You missed " + missed + " times. ");
            else if(missed > 0)
                System.out.println("You missed " + missed + " time. ");
            else
                System.out.println("You are great! ");
        }
    }

    public static int guessWord(String answer, String sign){
        Scanner input = new Scanner(System.in);

        int missed = 0;
        while(!answer.equals(sign)){
            System.out.print("(Guess) Enter a letter in word " + sign + " > ");
            String tmpUserInput = input.next();
            char userInput = tmpUserInput.charAt(0);
            // int already = 0;
            if(answer.indexOf(userInput) == -1){
                System.out.println("        " + userInput + " is not in the word.");
                missed++;
            }
            else{
                if(sign.indexOf(userInput) == -1){
                    int len = answer.length();
                    for(int i = 0; i < len; i++){
                        if(answer.charAt(i) == userInput)
                            sign = replace(sign, i, userInput);
                    }
                }
                else
                    System.out.println("        " + userInput + " is already in the word.");
            }
        }

        return missed;
    }

    public static String replace(String sign, int x, char c){

        String result = "";

        int len = sign.length();
        for(int i = 0; i < len; i++){
            if(i == x)
                result += c;
            else
                result += sign.charAt(i);
        }

        return result;
    }

    public static String creatWord(){

        String[] words = {"write", "read", "that", "program", "answer", "hello", "Chinese", "integer"};
        int len = words.length;

        return words[(int)(Math.random() * len)];
    }

    public static String creatSign(int len){
        
        String sign = "";
        for(int i = 0; i < len ;i++){

            sign = sign + "*";
        }

        return sign;
    }
}
