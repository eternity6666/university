import java.util.*;

public class exam21{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter year: (e.g., 2018): ");
        int year = input.nextInt();

        System.out.print("Enter month: 1-12: ");
        int month;
        do{
            month = input.nextInt();
            if(month <= 12 && month >= 1)
                break;
            System.out.print("Enter month: 1-12: ");
        }while(true);
        int tmpMonth = getDays(leapYear(year), month);

        System.out.print("Enter the day of the month: 1-" + tmpMonth +": ");
        int day;
        do{
            day = input.nextInt();
            if(day <= tmpMonth && day >= 1)
                break;
            System.out.print("Enter the day of the month: 1-" + tmpMonth +": ");
        }while(true);

        outputWeek(klstzl(year, month, day));
    }

    public static int klstzl(int year, int month, int day){
        int h, q, m, j, k;

        q = day;
        if(month <= 2){
            year--;
            m = month + 12;
        }
        else
            m = month;
        j = Math.abs(year) / 100;
        k = Math.abs(year) % 100;
        
        h = (q + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;

        return h;    
    }

    public static boolean leapYear(int year){
        if(year % 4 != 0)
            return false;
        else{
            if(year % 100 != 0)
                return true;
            else if(year % 400 == 0)
                return true;
            else
                return false;
            /*
            if(year % 400 == 0)
                return true;
            else if(year % 100 != 0)
                return true;
            else
                return false;
            */
        }
    }

    public static int getDays(boolean leap, int month){
        if(month != 2){
            if(month <= 7)
                if(month % 2 == 1)
                    return 31;
                else
                    return 30;
            else
                if(month % 2 == 1)
                    return 30;
                else
                    return 31;
        }
        else{
            if(leap)
                return 29;
            else
                return 28;
        }
    }

    public static void outputWeek(int h){

        String ans;
        switch(h){
            case 0:
                ans = "Saturday";
                break;
            case 1:
                ans = "Sunday";
                break;
            case 2:
                ans = "Monday";
                break;
            case 3:
                ans = "Tuesday";
                break;
            case 4:
                ans = "Wednesday";
                break;
            case 5:
                ans = "Thursday";
                break;
            case 6:
                ans = "Friday";
                break;
            default:
                ans = "**";
                    break;
        }
        System.out.println("Day of the week is " + ans);
    }
}

