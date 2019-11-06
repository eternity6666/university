package unit15.exam.out;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.geometry.Pos;
import javafx.scene.text.Text;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;

public class Exam04 extends Application {
    private TextField number1 = new TextField();
    private TextField number2 = new TextField();
    private TextField result = new TextField();
    private Button btAdd = new Button("Add");
    private Button btSubtract = new Button("Subtract");
    private Button btMultiply = new Button("Multiply");
    private Button btDivide = new Button("Divide");

    @Override
    public void start(Stage primaryStage) {
        GridPane gridPane = new GridPane();
        gridPane.setHgap(5);
        gridPane.setVgap(5);
        gridPane.add(new Label("Number 1 :"), 0, 0);
        gridPane.add(number1, 1, 0);
        gridPane.add(new Label("Number 2: "), 0, 1);
        gridPane.add(number2, 1, 1);
        gridPane.add(new Label("Result: "), 0, 2);
        gridPane.add(result, 1, 2);
        gridPane.setHgap(5);
        gridPane.setVgap(5);

        result.setEditable(false);
        number1.setAlignment(Pos.CENTER_RIGHT);
        number2.setAlignment(Pos.CENTER_RIGHT);
        result.setAlignment(Pos.CENTER_RIGHT);

        HBox hBox = new HBox();
        hBox.setAlignment(Pos.CENTER);
        hBox.setSpacing(1);
        hBox.getChildren().addAll(btAdd, btSubtract, btMultiply, btDivide);
        
        BorderPane pane = new BorderPane();
        pane.setTop(gridPane);
        pane.setBottom(hBox);
        pane.setAlignment(hBox, Pos.CENTER);

        btAdd.setOnAction(e -> add());
        btSubtract.setOnAction(e -> subtract());
        btMultiply.setOnAction(e -> multiply());
        btDivide.setOnAction(e -> divide());

        Scene scene = new Scene(pane);
        primaryStage.setTitle("创建一个简单的计算器");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private double getNumber1() {
        if(number1.getLength() == 0) {
            number1.setText("0");
            return 0;
        }
        return Double.parseDouble(number1.getText());
    }

    private double getNumber2() {
        if(number2.getLength() == 0) {
            number2.setText("0");
            return 0;
        }
        return Double.parseDouble(number2.getText());
    }

    private void setResult(double result) {
        this.result.setText(String.format("%f", result));
    }

    private void multiply() {
        setResult(getNumber1() * getNumber2());
    }

    private void divide() {
        try{
            setResult(getNumber1() / getNumber2());
        } catch(Exception e) {
            System.out.println("ERROR!!! Number2 is zero");
        }
    }

    private void subtract() {
        setResult(getNumber1() - getNumber2());
    }

    private void add() {
        setResult(getNumber1() + getNumber2());
    }

}

