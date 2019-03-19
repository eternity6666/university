import java.util.*;

public class example04{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        char[] chars = createArray();
        System.out.println("The lowercase letters are: ");
        displayChars(chars);

        int[] counts = countLetterr(chars);
        System.out.println();
        System.out.println("The occurrences of each letter are: ");
        displayCounts(counts);
    }

    public static char getRandomLowerCaseLetter(){
        // return char((int)'a' + (int)(Math.random() * ('z' - 'a' + 1)));
        char ans = (char)('a' + Math.random() * ('z' - 'a' + 1));
        return ans;
    }

    public static char[] createArray(){
        char[] chars = new char[100];

        int len = chars.length;
        for(int i = 0; i < len; i++){
            chars[i] = getRandomLowerCaseLetter();
        }
        return chars;
    }

    public static void displayChars(char[] chars){
        int len = chars.length;
        for(int i = 0; i < len; i++){
            if((i + 1) % 10 == 0)
                System.out.println(chars[i]);
            else
                System.out.print(chars[i] + " ");
        }
    }

    public static int[] countLetterr(char[] chars){
       int[] counts = new int[27];
       for(int i = 0; i < 27; i++){
           counts[i] = 0;
       }
       int len = chars.length;
       for(int i = 0; i < len; i++){
          counts[chars[i] - 'a']++; 
       }
       return counts;
    }

    public static void displayCounts(int[] counts){
        // int len = counts.length;
        for(int i = 0; i < 26; i++){
            System.out.print((char)('a' + i) + ":");
            if(counts[i] < 10)
                System.out.print(" ");
            if((i + 1) % 8 == 0) 
                System.out.println(counts[i]);
            else 
                System.out.print(counts[i] + "  ");
        }
        System.out.println();
    }
}

