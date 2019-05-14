// DescriptionPane.java

package unit16.example.out;

import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.text.Font;

public class Example06 extends BorderPane {
    private Label lblImageTitle = new Label();
    private TextArea taDescription = new TextArea();

    public Example06() {
        lblImageTitle.setContentDisplay(ContentDisplay.TOP);
        lblImageTitle.setPrefSize(200, 100);

        lblImageTitle.setFont(new Font("SanSerif", 16));
        taDescription.setFont(new Font("Serif", 14));

        taDescription.setWrapText(true);
        taDescription.setEditable(false);

        ScrollPane scrollpane = new ScrollPane(taDescription);

        setLeft(lblImageTitle);
        setCenter(scrollpane);
        setPadding(new Insets(5, 5, 5, 5));
    }
    
    public void setTitle(String title) {
        lblImageTitle.setText(title);
    }

    public void setImageView(ImageView icon) {
        lblImageTitle.setGraphic(icon);
    }

    public void setDescription(String text) {
        taDescription.setText(text);
    }
}

