// ShowEllipse.java

package unit14.example.out;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.Ellipse;

public class Example17 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();

        for (int i = 0; i < 32; i++) {
            // Ellipse e1 = new Ellipse((double)(pane.widthProperty().subtract(2)), (double)(pane.heightProperty().subtract(2)), 100, 50);
            Ellipse e1 = new Ellipse(250, 250, 250, 100);
            e1.setStroke(Color.color(Math.random(), Math.random(), Math.random()));
            e1.setFill(Color.WHITE);
            e1.setRotate(i * 180 / 32);
            pane.getChildren().add(e1);
        }

        Scene scene = new Scene(pane, 500, 500);
        primaryStage.setTitle("Show Ellipse");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
