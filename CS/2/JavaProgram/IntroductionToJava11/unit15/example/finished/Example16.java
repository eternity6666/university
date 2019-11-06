// ClockAnimation.java

package unit15.example.out;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.util.Duration;

public class Example16 extends Application {
    @Override
    public void start(Stage primaryStage) {
        unit14.example.out.ClockPane clock = new unit14.example.out.ClockPane();

        EventHandler<ActionEvent> eventHandler = e -> {
            clock.setCurrentTime();
        };

        Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), eventHandler));
        animation.setCycleCount(Timeline.INDEFINITE);
        animation.play();

        Scene scene = new Scene(clock, 250, 250);
        primaryStage.setTitle("Clock Animation");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

