package unit15.exam.out;

import javafx.application.Application;
import unit15.exam.out.ClockPane;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.geometry.Pos;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.util.Duration;

public class Exam32 extends Application {
    @Override
    public void start(Stage primaryStage) {
        BorderPane pane = new BorderPane();
        ClockPane clock = new ClockPane();
        pane.setCenter(clock);
        
        Button btStart = new Button("Start");
        Button btStop = new Button("Stop");

        EventHandler<ActionEvent> eventHandler = e -> {
            int tmpSecond = (clock.getHour() * 60 + clock.getMinute()) * 60 + clock.getSecond();
            tmpSecond++;
            clock.setSecond(tmpSecond % 60);
            clock.setMinute(tmpSecond / 60 % 60);
            clock.setHour(tmpSecond / 60 / 60);
            clock.paintClock();
        };

        Timeline animation = new Timeline(
            new KeyFrame(Duration.millis(1000), eventHandler)
        );
        animation.setCycleCount(Timeline.INDEFINITE);
        animation.play();

        btStart.setOnAction(e -> {
            animation.play();
        });

        btStop.setOnAction(e -> {
            animation.pause();
        });

        HBox hBox = new HBox();
        hBox.getChildren().addAll(btStop, btStart);
        hBox.setAlignment(Pos.CENTER);
        pane.setBottom(hBox);

        Scene scene = new Scene(pane, 250, 275);
        primaryStage.setTitle("控制时钟");
        primaryStage.setScene(scene);
        primaryStage.show(); 
    }
}

