package unit15.exam.out;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.shape.Rectangle;
import javafx.geometry.Pos;

public class Exam02 extends Application {
    @Override
    public void start(Stage primaryStage) {
        StackPane pane1 = new StackPane();
        Rectangle rectangle = new Rectangle(90, 35);
        rectangle.setFill(Color.RED);
        rectangle.setStroke(Color.BLUE);
        pane1.getChildren().add(rectangle);

        StackPane pane2 = new StackPane();
        Button btRotate = new Button("Rotate");
        pane2.getChildren().add(btRotate);

        BorderPane borderPane = new BorderPane();
        borderPane.setCenter(pane1);
        borderPane.setBottom(pane2);
    
        btRotate.setOnAction(e -> {
            rectangle.setRotate(rectangle.getRotate() + 15);
        });

        Scene scene = new Scene(borderPane, 250, 200);
        primaryStage.setTitle("旋转一个四边形");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

