// DisplayClock.java

package unit14.exam.out;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import unit14.example.out.*;;
import unit14.exam.out.*;

public class Exam27 extends Application {
    @Override
    public void start(Stage primaryStage) {
        ClockPane clock = new ClockPane();
        String timeString = clock.toString();
        Label lblCurrentTime = new Label(timeString);

        BorderPane pane = new BorderPane();
        pane.setCenter(clock);
        pane.setBottom(lblCurrentTime);
        pane.setAlignment(lblCurrentTime, Pos.TOP_CENTER);

        Scene scene = new Scene(pane, 250, 250);
        primaryStage.setTitle("DisplayClock");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

