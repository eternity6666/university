package unit16.exam.out;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.scene.paint.Color;

public class Exam01 extends Application {
    @Override
    public void start(Stage primaryStage) {
        BorderPane pane = new BorderPane();
        
        Pane paneForText = new Pane();
        Text text = new Text(40, 50, "Programming is fun");
        paneForText.getChildren().add(text);
        paneForText.setStyle("-fx-border-color: black");
        pane.setCenter(paneForText);

        HBox paneForButton = new HBox();
        Button btLeft = new Button("<=");
        Button btRight = new Button("=>");
        paneForButton.getChildren().addAll(btLeft, btRight);
        paneForButton.setAlignment(Pos.CENTER);
        pane.setBottom(paneForButton);

        btLeft.setOnAction(e -> {
            text.setX(text.getX() - 10);
        });
        btRight.setOnAction(e -> {
            text.setX(text.getX() + 10);
        });

        HBox paneForRadioButton = new HBox();
        RadioButton rbRed = new RadioButton("Red");
        RadioButton rbYellow = new RadioButton("Yellow");
        RadioButton rbBlack = new RadioButton("Black");
        RadioButton rbOrange = new RadioButton("Orange");
        RadioButton rbGreen = new RadioButton("Green");
        paneForRadioButton.getChildren().addAll(rbRed, rbYellow, rbBlack, rbOrange, rbGreen);
        paneForRadioButton.setAlignment(Pos.CENTER);
        pane.setTop(paneForRadioButton);

        ToggleGroup group = new ToggleGroup();
        rbRed.setToggleGroup(group);
        rbYellow.setToggleGroup(group);
        rbBlack.setToggleGroup(group);
        rbOrange.setToggleGroup(group);
        rbGreen.setToggleGroup(group);

        rbRed.setOnAction(e -> {
            if(rbRed.isSelected()) {
                text.setFill(Color.RED);
            }
        });

        rbYellow.setOnAction(e -> {
            if(rbYellow.isSelected()) {
                text.setFill(Color.YELLOW);
            }
        });

        rbBlack.setOnAction(e -> {
            if(rbBlack.isSelected()) {
                text.setFill(Color.BLACK);
            }
        });

        rbOrange.setOnAction(e -> {
            if(rbOrange.isSelected()) {
                text.setFill(Color.ORANGE);
            }
        });

        rbGreen.setOnAction(e -> {
            if(rbGreen.isSelected()) {
                text.setFill(Color.GREEN);
            }
        });

        Scene scene = new Scene(pane, 400, 200);
        primaryStage.setTitle("使用单选按钮");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

