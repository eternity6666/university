import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Game2048 extends BorderPane {
    private int score;
    private int[][] game;

    public Game2048() {
        newGame();

        setOnKeyPressed(e -> {
            switch (e.getCode()) {
                case DOWN:
                    down();
                    break;
                case UP:
                    up();
                    break;
                case RIGHT:
                    right();
                    break;
                case LEFT:
                    left();
                    break;
                default:
                    break;
            }
            if(isFull() && (!canCol()) && (!canRow())) {
                BorderPane pane = new BorderPane();

                Text text = new Text("Game Over!\nYour score is " + getScore());
                pane.setTop(text);

                Button btNewGame = new Button("New Game");
                btNewGame.setPrefWidth(200);

                Button btQuit = new Button("Quit");
                btQuit.setPrefWidth(200);

                GridPane gridPane = new GridPane();
                gridPane.add(btNewGame, 0, 0);
                gridPane.add(btQuit, 1, 0);
                gridPane.setVgap(5);
                gridPane.setHgap(5);
                gridPane.setAlignment(Pos.CENTER);

                pane.setCenter(gridPane);

                Scene scene = new Scene(pane);
                Stage stage = new Stage();
                stage.setTitle("Score");
                stage.setScene(scene);
                stage.show();

                btNewGame.setOnAction(e1 -> {
                    newGame();
                    stage.close();
                });

                btQuit.setOnAction(e1 -> quit());
            }
            set();
        });
    }

    public void quit() {
        System.exit(1);
    }

    public void set() {
        setCenter(new Chess(getGame()));
        setBottom(new Score(getScore()));
    }

    public void down() {
        if ((!isFull()) || canCol()) {
            int[][] tmp = getGame();
            for(int j = 0; j < 4; j++) {
                boolean flag = true;
                while (flag) {
                    flag = false;
                    for (int i = 0; i < 3; i++) {
                        if (tmp[i + 1][j] == 0) {
                            if(tmp[i][j] != 0) {
                                tmp[i + 1][j] = tmp[i][j];
                                flag = true;
                            }
                            tmp[i][j] = 0;
                        }
                        else if (tmp[i][j] == tmp[i + 1][j]) {
                            tmp[i + 1][j] = tmp[i][j] + tmp[i + 1][j];
                            tmp[i][j] = 0;
                            score = score + tmp[i + 1][j];
                            flag = true;
                        }
                    }
                }
            }
            int a, b;
            do {
                a = (int)(Math.random() * 100) % 4;
                b = (int)(Math.random() * 100) % 4;
            }while(tmp[a][b] != 0);
            tmp[a][b] = newNumber();
            game = tmp;
        }
    }

    public void up() {
        if ((!isFull()) || canCol()) {
            int[][] tmp = getGame();
            for(int j = 0; j < 4; j++) {
                boolean flag = true;
                while (flag) {
                    flag = false;
                    for (int i = 3; i > 0; i--) {
                        if (tmp[i - 1][j] == 0) {
                            if(tmp[i][j] != 0) {
                                tmp[i - 1][j] = tmp[i][j];
                                flag = true;
                            }
                            tmp[i][j] = 0;
                        } else if (tmp[i][j] == tmp[i - 1][j]) {
                            tmp[i - 1][j] = tmp[i][j] + tmp[i - 1][j];
                            tmp[i][j] = 0;
                            score = score + tmp[i - 1][j];
                            flag = true;
                        }
                    }
                }
            }
            int a, b;
            do {
                a = (int)(Math.random() * 100) % 4;
                b = (int)(Math.random() * 100) % 4;
            }while(tmp[a][b] != 0);
            tmp[a][b] = newNumber();
            game = tmp;
        }
    }

    public void left() {
        if ((!isFull()) || canRow()) {
            int[][] tmp = getGame();
            for(int i = 0; i < 4; i++) {
                boolean flag = true;
                while (flag) {
                    flag = false;
                    for (int j = 3; j > 0; j--) {
                        if (tmp[i][j - 1] == 0) {
                            if(tmp[i][j] != 0) {
                                tmp[i][j - 1] = tmp[i][j];
                                flag = true;
                            }
                            tmp[i][j] = 0;
                        }
                        else if (tmp[i][j] == tmp[i][j - 1]) {
                            tmp[i][j - 1] = tmp[i][j] + tmp[i][j - 1];
                            tmp[i][j] = 0;
                            score = score + tmp[i][j - 1];
                            flag = true;
                        }
                    }
                }
            }
            int a, b;
            do {
                a = (int)(Math.random() * 100) % 4;
                b = (int)(Math.random() * 100) % 4;
            }while(tmp[a][b] != 0);
            tmp[a][b] = newNumber();
            game = tmp;
        }
    }

    public void right() {
        if ((!isFull()) || canRow()) {
            int[][] tmp = getGame();
            for(int i = 0; i < 4; i++) {
                boolean flag = true;
                while (flag) {
                    flag = false;
                    for (int j = 0; j < 3; j++) {
                        if (tmp[i][j + 1] == 0) {
                            if(tmp[i][j] != 0) {
                                tmp[i][j + 1] = tmp[i][j];
                                flag = true;
                            }
                            tmp[i][j] = 0;
                        }
                        else if (tmp[i][j] == tmp[i][j + 1]) {
                            tmp[i][j + 1] = tmp[i][j] + tmp[i][j + 1];
                            tmp[i][j] = 0;
                            score = score + tmp[i][j + 1];
                            flag = true;
                        }
                    }
                }
            }
            int a, b;
            do {
                a = (int)(Math.random() * 100) % 4;
                b = (int)(Math.random() * 100) % 4;
            }while(tmp[a][b] != 0);
            tmp[a][b] = newNumber();
            game = tmp;
        }
    }

    private boolean isFull() {
        for(int i = 0; i < game.length; i++)
            for(int j = 0; j < game[i].length; j++)
                if(game[i][j] == 0)
                    return false;
        return true;
    }

    private boolean canRow() {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 3; j++)
                if(game[i][j] == game[i][j + 1])
                    return true;
        return false;
    }

    private boolean canCol() {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 4; j++)
                if(game[i][j] == game[i + 1][j])
                    return true;
        return false;
    }

    private int newNumber() {
        int number = (int)(Math.random() * 100);
        if(number % 5 == 0)
            return 4;
        else
            return 2;
    }

    public int getScore() {
        return score;
    }

    public int[][] getGame() {
        return game;
    }

    public void newGame() {
        score = 0;
        game = new int[4][4];
        int a, b, c, d;
        a = (int)(Math.random() * 100) % 4;
        b = (int)(Math.random() * 100) % 4;
        c = (int)(Math.random() * 100) % 4;
        do {
            d = (int)(Math.random() * 100) % 4;
        }while (b == d);
        game[a][b] = newNumber();
        game[c][d] = newNumber();
        set();
    }
}

class Score extends BorderPane {
    public Score(int score) {
        String string = "Score: " + score;
        setStyle("-fx-font-size:100;-fx-padding: 0");
        Text text = new Text(0, 0, string);
        setCenter(text);
    }
}

class Chess extends GridPane {
    public Chess(int[][] game) {
        setStyle("-fx-border-color: black");
        for(int i = 0; i < game.length; i++)
            for(int j = 0; j < game[i].length; j++)
                add(new Cell(game[i][j], (i + j) % 2), j, i);
    }
}

class Cell extends BorderPane {
    public Cell(int x, int color) {
        setPrefSize(200, 200);
        if(color == 0)
            setStyle("-fx-border-color: black;-fx-font-size:100;-fx-background-color: #ffff00");
        else
            setStyle("-fx-border-color: black;-fx-font-size:100;-fx-background-color: #e6e600");
        String string;
        if (x == 0)
            string = " ";
        else
            //string = (String)x;
            string = new Integer(x).toString();
        Text text = new Text(string);
        setCenter(text);
    }
}


