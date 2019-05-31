package unit16.exam.out;

import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;

public class Exam03 extends Application {
    @Override 
    public void start(Stage primaryStage) throws Exception {
        BorderPane pane = new BorderPane();

        Pane paneForLight = new Pane();
        Rectangle rectangle = new Rectangle();
        rectangle.setFill(Color.WHITE);
        rectangle.setStroke(Color.BLACK);
        rectangle.xProperty().bind(paneForLight.widthProperty().divide(20.0/9));
        rectangle.yProperty().bind(paneForLight.heightProperty().divide(20));
        rectangle.widthProperty().bind(paneForLight.widthProperty().divide(20.0/2));
        rectangle.heightProperty().bind(paneForLight.heightProperty().divide(10.0/9));
        paneForLight.getChildren().add(rectangle);

        Circle circle1 = new Circle();
        Circle circle2 = new Circle();
        Circle circle3 = new Circle();
        circle1.setFill(Color.RED);
        circle1.setStroke(Color.BLACK);
        circle1.centerXProperty().bind(paneForLight.widthProperty().divide(2));
        circle1.centerYProperty().bind(paneForLight.heightProperty().divide(12.0/2));
        circle1.radiusProperty().bind(paneForLight.widthProperty().divide(40));

        circle2.setFill(Color.WHITE);
        circle2.setStroke(Color.BLACK);
        circle2.centerXProperty().bind(paneForLight.widthProperty().divide(2));
        circle2.centerYProperty().bind(paneForLight.heightProperty().divide(12.0/6));
        circle2.radiusProperty().bind(paneForLight.widthProperty().divide(40));

        circle3.setFill(Color.WHITE);
        circle3.setStroke(Color.BLACK);
        circle3.centerXProperty().bind(paneForLight.widthProperty().divide(2));
        circle3.centerYProperty().bind(paneForLight.heightProperty().divide(12.0/10));
        circle3.radiusProperty().bind(paneForLight.widthProperty().divide(40));

        paneForLight.getChildren().addAll(circle1, circle2, circle3);
        
        pane.setCenter(paneForLight);

        HBox paneForRadioButtons = new HBox(50);
        paneForRadioButtons.setPadding(new Insets(5, 5, 5, 5));
        paneForRadioButtons.setAlignment(Pos.CENTER);

        RadioButton rbRed = new RadioButton("Red");
        RadioButton rbYellow = new RadioButton("Yellow");
        RadioButton rbGreen = new RadioButton("Green");
        paneForRadioButtons.getChildren().addAll(rbRed, rbYellow, rbGreen);
        
        pane.setBottom(paneForRadioButtons);

        ToggleGroup group = new ToggleGroup();
        rbRed.setToggleGroup(group);
        rbYellow.setToggleGroup(group);
        rbGreen.setToggleGroup(group);

        rbRed.setOnAction(e -> {
            if(rbRed.isSelected()) {
                circle1.setFill(Color.RED);
                circle2.setFill(Color.WHITE);
                circle3.setFill(Color.WHITE);
            }
        });
       
        rbYellow.setOnAction(e -> {
            if(rbYellow.isSelected()) {
                circle1.setFill(Color.WHITE);
                circle2.setFill(Color.YELLOW);
                circle3.setFill(Color.WHITE);
            }
        });

        rbGreen.setOnAction(e -> {
            if(rbGreen.isSelected()) {
                circle1.setFill(Color.WHITE);
                circle2.setFill(Color.WHITE);
                circle3.setFill(Color.GREEN);
            }
        });

        Scene scene = new Scene(pane, 500, 300);
        primaryStage.setTitle("交通信号灯");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

