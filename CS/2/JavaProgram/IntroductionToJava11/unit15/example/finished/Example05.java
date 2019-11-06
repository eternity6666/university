// LambdaHandlerDemo.java

package unit15.example.out;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class Example05 extends Application {
    @Override
    public void start(Stage primaryStage) {
        HBox hBox = new HBox();
        hBox.setSpacing(10);
        hBox.setAlignment(Pos.CENTER);
        Button btNew = new Button("New");
        Button btOpen = new Button("Open");
        Button btSave = new Button("Save");
        Button btPrint = new Button("Print");
        hBox.getChildren().addAll(btNew, btOpen, btSave, btPrint);

        btOpen.setOnAction(e -> System.out.println("Process Print"));
    
        btSave.setOnAction(e -> System.out.println("Process Print"));
    
        btNew.setOnAction(e -> System.out.println("Process New"));
    
        btPrint.setOnAction(e -> System.out.println("Process Print"));
    
        Scene scene = new Scene(hBox, 300, 50);
        primaryStage.setTitle("Anonymous Handler Demo");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

