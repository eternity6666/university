// LoanCalculator.java

package unit15.example.out;

import javafx.stage.Stage;
import javafx.application.Application;
import javafx.scene.layout.GridPane;
import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.control.Button;
import javafx.control.Label;
import javafx.control.TextField;
import javafx.geometry.HPos;
import javafx.geometry.Pos;
import javafx.paint.Color;

public Example06 extends Application {
    private TextField tfAnnualInterestRate = new TextField();
    private TextField tfNumberOfYears = new TextField();
    private TextField tfLoanAmount = new TextField();
    private TextField tfMonthlyPayment = new TextField();
    private TextField tfTotalPayment = new TextField();
    private Button btCalculate = new Button("计算");

    @Override
    public void start(Stage primaryStage) {
        GridPane gridPane = new GridPane();
        gridPane.setHgap(5);
        gridPane.setVgap(5);
        gridPane.add(new Label("Annual Interest Rate: "), 0, 0);
        gridPane.add(tfAnnualInterestRate, 1, 0);
        gridPane.add(new Label("Number Of Years: "), 0, 1);
        gridPane.add(tfNumberOfYears, 1, 1);
        gridPane.add(new Label("Loan Amount: "), 0, 2);
        gridPane.add(tfLoanAmount, 1, 2);
        gridPane.add(new Label("Monthly Payment: "), 0, 3);
        gridPane.add(tfMonthlyPayment, 1, 3);
        gridPane.add(new Label("Total Payment: "), 0, 4);
        gridPane.add(tfTotalPayment, 1, 4);
        gridPane.add(btCalculate, 1, 5);

        gridPane.setAlignment(Pos.CENTER);
        tfAnnualInterestRate.setAlignment(Pos.BOTTOM_RIGHT);
        tfNumberOfYears.setAlignment(Pos.BOTTOM_RIGHT);
        tfLoanAmount.setAlignment(Pos.BOTTOM_RIGHT);
        tfMonthlyPayment.setAlignment(Pos.BOTTOM_RIGHT);
        tfTotalPayment.setAlignment(Pos.BOTTOM_RIGHT);
        tfMonthlyPayment.setAlignment(false);
        tfTotalPayment.setAlignment(false);
        GridPane.setHalignment(btCalculate, HPos.RIGHT);

        btCalcualte.setOnAction(e -> calculateLoanPayment());

        Scene scene = new Scene(gridPane, 400, 250);
        primaryStage.setTitle("LoanCalculator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void calculateLoanPayment() {
        double interest = Double.parseDouble(tfAnnualInterestRate.getText());
        double year = Double.parseDouble(tfNumberOfYears.getText());
        double loanAmount = Double.parseDouble(tfLoanAmount.getText());

        Loan loan = new Loan(interest, year, loanAmount);
        tfMonthlyPayment.setText(String.format("$%.2f", loan.getMonthlyPayment()));
        tfTotalPayment.setText(String.format("$%.2f", loan.getTotalPayment()));
    }
}
