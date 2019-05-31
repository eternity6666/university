// 几何问题: 是否在圆内?
package unit15.exam.out;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.scene.text.Text;
import javafx.scene.paint.Color;

public class Exam12 extends Application {
    Circle circle;

    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();

        circle = new Circle();
        circle.setCenterX(100);
        circle.setCenterY(60);
        circle.setRadius(50);
        circle.setFill(Color.WHITE);
        circle.setStroke(Color.BLACK);
        pane.getChildren().add(circle);

        Text text = new Text(20, 20, "在圆内");
        pane.getChildren().add(text);

        pane.setOnMouseMoved(e -> {
            text.setX(e.getX());
            text.setY(e.getY());

            int status = mouseAndCircle(e.getX(), e.getY());
            if(status == 1)
                text.setText("在圆外");
            else if(status == 0)
                text.setText("在圆上");
            else
                text.setText("在圆内");
        });

        Scene scene = new Scene(pane, 250, 250);
        primaryStage.setScene(scene);
        primaryStage.setTitle("几何问题: 是否在圆内?");
        primaryStage.show();
    }

    private int mouseAndCircle(double x, double y) {
        double l = Math.sqrt(Math.pow(circle.getCenterX() - x, 2) + Math.pow(circle.getCenterY() - y, 2));
        if(l > circle.getRadius())
            return 1;
        else if(l == circle.getRadius())
            return 0;
        else
            return -1;
    }
}

