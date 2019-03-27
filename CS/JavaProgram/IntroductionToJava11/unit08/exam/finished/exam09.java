import java.util.Scanner;

public class exam09{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        while(true){
            System.out.print("Game Start! [Y/n] ");
            char yn;
            String tmpYN = input.next();
            yn = tmpYN.charAt(0);
            if(yn != 'Y' && yn != 'y')
                break;

            // char[][] chessboard = new char[3][3];
            int[][] chessboard = new int[3][3];

            for(int i = 0; i < chessboard.length; i++)
                for(int j = 0; j < chessboard[i].length; j++)
                    chessboard[i][j] = 0;

            char player1, player2;
            player1 = 'X';
            player2 = 'O';
            char winer = 'w';
            boolean flag = false;
            for(int i = 0; i < 9; i++){
                printChessboard(chessboard, player1, player2);
                int row;
                int col;
                do{
                    if(i % 2 == 0){
                        System.out.print("Enter a row (0, 1, or 2) for player " + player1 + ": ");
                        row = input.nextInt();
                        System.out.print("Enter a column (0, 1, or 2) for player " + player1 + ": ");
                        col = input.nextInt();
                    }
                    else{
                        System.out.print("Enter a row (0, 1, or 2) for player " + player2 + ": ");
                        row = input.nextInt();
                        System.out.print("Enter a column (0, 1, or 2) for player " + player2 + ": ");
                        col = input.nextInt();
                    }
                    if(row <= 2 && col <= 2 && row >= 0 && col >= 0){
                        if(chessboard[row][col] != 0)
                            System.out.println("Hint! The cell whose row = " + row + " and column = " + col + " has been input");
                        else
                            break;
                    }
                    else
                        System.out.println("Hint! The range of row and the range of column is 0, 1 or 2");
                }while(true);
                if(i % 2 == 0)
                    chessboard[row][col] = 1;
                else
                    chessboard[row][col] = 2;
                if(isWin(chessboard)) {
                    if(i % 2 == 0)
                        winer = player1;
                    else
                        winer = player2;
                    flag = true;
                    break;
                }
                else
                    continue;
            }
            printChessboard(chessboard, player1, player2);
            if(flag)
                System.out.println(winer + " player won");
            else
                System.out.println("No one won");
        }
    }

    public static boolean isWin(int[][] chessboard) {
        for(int i = 0; i < chessboard.length; i++)
            if(chessboard[i][0] != 0 && chessboard[i][0] == chessboard[i][1] && chessboard[i][0] == chessboard[i][2])
                return true;

        for(int i = 0; i < chessboard[0].length; i++)
            if(chessboard[0][i] != 0 && chessboard[0][i] == chessboard[1][i] && chessboard[0][i] == chessboard[2][i])
                return true;

        if(chessboard[1][1] != 0 && chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2])
            return true;

        if(chessboard[1][1] != 0 && chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0])
            return true;

        return false;
    }

    public static void printChessboard(int[][] chessboard, char player1, char player2){
        printRow(chessboard.length);
        for(int i = 0; i < chessboard.length; i++){
            System.out.print("|");
            for(int j = 0; j < chessboard[i].length; j++){
                System.out.print(" ");
                switch(chessboard[i][j]){
                    case 0:
                        System.out.print(" ");
                        break;
                    case 1:
                        System.out.print(player1);
                        break;
                    case 2:
                        System.out.print(player2);
                }
                System.out.print(" |");
            }
            System.out.println();
            printRow(chessboard.length);
        }
    }

    public static void printRow(int len){
        for(int i = 0; i < len + 1 + len * 3; i++)
            System.out.print("-");
        System.out.println();
    }
}

