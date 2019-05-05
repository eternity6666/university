// ControlCircleWithoutEventHandling.java

package unit15.example.out;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.BorderPane;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Example02 extends Application {
    @Override
    public void start(Stage primaryStage) {
        StackPane pane = new StackPane();
        Circle circle = new Circle();
        circle.setStroke(Color.BLACK);
        circle.setFill(Color.WHITE);
        pane.getChildren().add(circle);

        HBox hBox = new HBox();
        hBox.setSpacing(10);
        hBox.setAlignment(Pos.CENTER);
        Button btEnlarge = new Button("Enlarge");
        Button btShrink = new Button("Shrink");
        hBox.getChildren().add(btEnlarge);
        hBox.getChildren().add(btShrink);

        BorderPane borderPane = new BorderPane();
        borderPane.setCenter(pane);
        borderPane.setBottom(hBox);
        borderPane.setAlignment(hBox, Pos.CENTER);

        Scene scene = new Scene(borderPane, 200, 150);
        primaryStage.setTitle("Control Circle");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

