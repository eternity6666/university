package unit14.review.out;

import javafx.application.Application;
import javafx.stage.Stage;

public class review04 extends Application {
    public review04() {
        System.out.println("Test constructor is invoked");
    }
    @Override
    public void start(Stage primaryStage) {
        System.out.println("start method is invoked");
    }

    public static void main(String[] args) {
        System.out.println("launch application");
        Application.launch(args);
    }
}

