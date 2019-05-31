import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        Game2048 game2048 = new Game2048();

        Scene scene = new Scene(game2048);
        primaryStage.setTitle("2048");
        primaryStage.setScene(scene);
        primaryStage.show();

        game2048.requestFocus();
    }
}

