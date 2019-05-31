package unit14.exam.out;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.paint.Color;
import javafx.scene.layout.Pane;

public class Exam11 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();

        Circle circle1 = new Circle();
        circle1.setStroke(Color.BLACK);
        circle1.setFill(Color.YELLOW);
        circle1.setRadius(225);
        circle1.setCenterX(250);
        circle1.setCenterY(250);

        Circle circle2 = new Circle();
        circle2.setStroke(Color.BLACK);
        circle2.setFill(Color.BLACK);
        circle2.setRadius(30);
        circle2.setCenterX(500.0/3);
        circle2.setCenterY(500.0/3);

        Circle circle3 = new Circle();
        circle3.setStroke(Color.BLACK);
        circle3.setFill(Color.BLACK);
        circle3.setRadius(30);
        circle3.setCenterX(500.0 * 2 / 3);
        circle3.setCenterY(500.0/3);
        
        Ellipse ellipse1 = new Ellipse();
        ellipse1.setStroke(Color.BLACK);
        ellipse1.setFill(Color.WHITE);
        ellipse1.setCenterX(500.0/3);
        ellipse1.setCenterY(500.0/3);
        ellipse1.setRadiusX(60);
        ellipse1.setRadiusY(45);

        Ellipse ellipse2 = new Ellipse();
        ellipse2.setStroke(Color.BLACK);
        ellipse2.setFill(Color.WHITE);
        ellipse2.setCenterX(500.0 * 2 / 3);
        ellipse2.setCenterY(500.0/3);
        ellipse2.setRadiusX(60);
        ellipse2.setRadiusY(45);

        pane.getChildren().addAll(circle1, ellipse1, ellipse2, circle2, circle3);

        Polygon triangle = new Polygon(500.0 / 2, 500.0 * 5 / 12, 500.0 * 5 / 12, 500.0 * 7 / 12, 500.0 * 7 / 12, 500.0 * 7 / 12);
        triangle.setStroke(Color.BLACK);
        triangle.setFill(Color.WHITE);
        pane.getChildren().add(triangle);

        Arc arc = new Arc();
        arc.setStroke(Color.BLACK);
        arc.setFill(Color.YELLOW);
        arc.setCenterX(500.0/2);
        arc.setCenterY(500.0 * 8 / 12);
        arc.setRadiusX(500.0 / 6);
        arc.setRadiusY(500.0 / 12);
        arc.setType(ArcType.OPEN);
        arc.setStartAngle(0);
        arc.setLength(-180);
        pane.getChildren().add(arc);


        Scene scene = new Scene(pane, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("绘制一个笑脸");
        primaryStage.show();
    }
}


