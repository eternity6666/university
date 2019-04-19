// ShowPolygon.java

package unit14.example.out;

import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.scene.shape.*;

public class Example19 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();
        /*
        Polygon polygon2 = new Polygon(120.0, 100.0, 120.0, 110.0, 130.0, 120.0);
        polygon2.setFill(Color.RED);
        polygon2.setStroke(Color.BLACK);
        pane.getChildren().add(polygon2);
        */
        Polygon polygon = new Polygon();
        polygon.setFill(Color.GREEN);
        ObservableList<Double> list = polygon.getPoints();
        pane.getChildren().add(polygon);

        final double WIDTH = 200, HEIGHT = 200;
        double centerX = WIDTH / 2, centerY = HEIGHT / 2;
        double radius = Math.min(WIDTH, HEIGHT) * 0.4;

        // System.out.println(radius);

        for(int i = 0; i < 6; i++){
            list.add(centerX + radius * Math.cos(2 * i * Math.PI / 6));
            list.add(centerY - radius * Math.sin(2 * i * Math.PI / 6));
        }

        Scene scene = new Scene(pane, WIDTH, HEIGHT);
        primaryStage.setTitle("Show Polygon");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

