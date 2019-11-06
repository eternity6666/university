// TextAreaDemo.java

package unit16.example.out;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import unit16.example.out.*;

public class Example07 extends Application {
    @Override
    public void start(Stage primaryStage) {
        Example06 descriptionPane = new Example06();
        descriptionPane.setTitle("Canada");
        String description = "The Canadian national flag ...";
        descriptionPane.setImageView(new ImageView("https://ss3.baidu.com/-fo3dSag_xI4khGko9WTAnF6hhy/image/h%3D300/sign=b5e4c905865494ee982209191df4e0e1/c2cec3fdfc03924590b2a9b58d94a4c27d1e2500.jpg"));
        descriptionPane.setDescription(description);

        Scene scene = new Scene(descriptionPane, 450, 200);
        primaryStage.setTitle("Text Area Demo");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

