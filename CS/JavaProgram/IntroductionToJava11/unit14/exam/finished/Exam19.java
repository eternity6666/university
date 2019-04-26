// package unit14.exam.out.Exam19;

import javafx.application.Application;
import javafx.scene.shape.Line;
import javafx.collections.ObservableList;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polyline;

public class Exam19 extends Application {
    @Override
    public void start(Stage primaryStage) {

        double width = 1000;
        double height = 500;
        double scalieFactor = 50;

        Pane pane = new Pane();
        Polyline sinline = new Polyline();
        pane.getChildren().add(sinline);
        sinline.setStroke(Color.RED);
        ObservableList<Double> sinList = sinline.getPoints();
        for(int x = -(int)(width / 12 * 4.9); x <= (width / 12 * 4.9); x++) {
            sinList.add(x + width * 6 / 12.0);
            sinList.add(height / 2 - height * 2 / 5 * Math.sin((x / (width / 12 * 4.9)) * 2 * Math.PI));
        }

        Polyline cosline = new Polyline();
        pane.getChildren().add(cosline);
        cosline.setStroke(Color.BLUE);
        ObservableList<Double> cosList = cosline.getPoints();
        for(int x = -(int)(width / 12 * 4.9); x <= (width / 12 * 4.9); x++) {
            cosList.add(x + width * 6 / 12.0);
            cosList.add(height / 2 - height * 2 / 5 * Math.cos((x / (width / 12 * 4.9)) * 2 * Math.PI));
        }

        Line x = new Line();
        x.startXProperty().bind(pane.widthProperty().divide(24.0/1));
        x.startYProperty().bind(pane.heightProperty().divide(2));
        x.endXProperty().bind(pane.widthProperty().divide(24.0/23));
        x.endYProperty().bind(pane.heightProperty().divide(2));
        x.setStroke(Color.BLACK);
        pane.getChildren().add(x);

        Line xBrokenLine1 = new Line();
        xBrokenLine1.startXProperty().bind(pane.widthProperty().divide(24.0/23));
        xBrokenLine1.startYProperty().bind(pane.heightProperty().divide(2));
        xBrokenLine1.endXProperty().bind(pane.widthProperty().divide(48.0/45));
        xBrokenLine1.endYProperty().bind(pane.heightProperty().divide(2).subtract(pane.widthProperty().divide(48.0 * Math.tan(Math.PI/3))));
        xBrokenLine1.setStroke(Color.BLACK);
        pane.getChildren().add(xBrokenLine1);


        Line xBrokenLine2 = new Line();
        xBrokenLine2.startXProperty().bind(pane.widthProperty().divide(24.0/23));
        xBrokenLine2.startYProperty().bind(pane.heightProperty().divide(2));
        xBrokenLine2.endXProperty().bind(pane.widthProperty().divide(48.0/45));
        xBrokenLine2.endYProperty().bind(pane.heightProperty().divide(2).add(pane.widthProperty().divide(48.0 * Math.tan(Math.PI/3))));
        xBrokenLine2.setStroke(Color.BLACK);
        pane.getChildren().add(xBrokenLine2);

        Line y = new Line();
        y.startXProperty().bind(pane.widthProperty().divide(2));
        y.startYProperty().bind(pane.heightProperty().divide(24.0/1));
        y.endXProperty().bind(pane.widthProperty().divide(2));
        y.endYProperty().bind(pane.heightProperty().divide(24.0/23));
        y.setStroke(Color.BLACK);
        pane.getChildren().add(y);

        Line yBrokenLine1 = new Line();
        yBrokenLine1.startXProperty().bind(pane.widthProperty().divide(2));
        yBrokenLine1.startYProperty().bind(pane.heightProperty().divide(24.0/1));
        yBrokenLine1.endXProperty().bind(pane.widthProperty().divide(2).subtract(pane.heightProperty().divide(48.0 * Math.tan(Math.PI/3))));
        yBrokenLine1.endYProperty().bind(pane.heightProperty().divide(48.0/3));
        yBrokenLine1.setStroke(Color.BLACK);
        pane.getChildren().add(yBrokenLine1);

        Line yBrokenLine2 = new Line();
        yBrokenLine2.startXProperty().bind(pane.widthProperty().divide(2));
        yBrokenLine2.startYProperty().bind(pane.heightProperty().divide(24.0/1));
        yBrokenLine2.endXProperty().bind(pane.widthProperty().divide(2).add(pane.heightProperty().divide(48.0 * Math.tan(Math.PI/3))));
        yBrokenLine2.endYProperty().bind(pane.heightProperty().divide(48.0/3));
        yBrokenLine2.setStroke(Color.BLACK);
        pane.getChildren().add(yBrokenLine2);

        Scene scene = new Scene(pane, width, height);
        primaryStage.setTitle("Button in a pane");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

/*
class BrokenLine extends Line {
    public BrokenLine() {
    
    }
}
*/

