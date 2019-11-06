// FlagRisingAnimation.java

package unit15.example.out;

import javafx.animation.PathTransition;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Example13 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane();

        ImageView imageView = new ImageView("http://lib.ncu.edu.cn/images/default/public/img/x-logo.png");
        pane.getChildren().add(imageView);

        PathTransition pt = new PathTransition(Duration.millis(10000), new Line(300, 500, 300, 100), imageView);
        pt.setCycleCount(1);
        pt.play();

        Scene scene = new Scene(pane, 600, 600);
        primaryStage.setTitle("Flag Rising Animation");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

