// SliderDemo.java

package unit16.example.out;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.geometry.Orientation;
import javafx.scene.control.Slider;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;

public class Example11 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Text text = new Text(20, 20, "JavaFX Programming");
        Slider slHorizontal = new Slider();
        slHorizontal.setShowTickLabels(true);
        slHorizontal.setShowTickMarks(true);

        Slider slVertical = new Slider();
        slVertical.setOrientation(Orientation.VERTICAL);
        slVertical.setShowTickLabels(true);
        slVertical.setShowTickMarks(true);

        Pane paneForText = new Pane();
        paneForText.getChildren().add(text);

        BorderPane pane = new BorderPane();
        pane.setCenter(paneForText);
        pane.setBottom(slHorizontal);
        pane.setRight(slVertical);

        slHorizontal.valueProperty().addListener(ov -> text.setX(slHorizontal.getValue() * paneForText.getWidth() / slHorizontal.getMax()));
        slVertical.valueProperty().addListener(ov -> text.setY(slVertical.getValue() * paneForText.getWidth() / slVertical.getMax()));

        Scene scene = new Scene(pane, 450, 170);
        primaryStage.setTitle("Slider Demo");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

