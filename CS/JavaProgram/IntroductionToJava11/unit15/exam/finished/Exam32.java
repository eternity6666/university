package unit15.exam.out;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.geometry.Pos;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.util.Duration;
import unit14.example.out.*;

public class Exam32 extends Application {
    @Override
    public void start(Stage primaryStage) {
        BorderPane pane = new BorderPane();
        ClockPane clock = new ClockPane();
        pane.setTop(clock);

        pane.setCenter(new Label(clock.toString()));
    
        Button btStart = new Button("Start");
        Button btStop = new Button("Stop");

        EventHandler<ActionEvent> eventHandler = e -> {
            int tmpSecond = (clock.getHour() * 60 + clock.getMinute()) * 60 + clock.getSecond();
            tmpSecond++;
            clock.setSecond(tmpSecond % 60);
            clock.setMinute(tmpSecond / 60 % 60);
            clock.setHour(tmpSecond / 60 / 60);
            clock.paintClock();
            pane.setCenter(new Label(clock.toString()));
        };

        Timeline animation = new Timeline(
            new KeyFrame(Duration.millis(1000), eventHandler)
        );
        animation.setCycleCount(Timeline.INDEFINITE);

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

        Scene scene = new Scene(pane, 250, 300);
        primaryStage.setTitle("控制时钟");
        primaryStage.setScene(scene);
        primaryStage.show(); 
    }
}

