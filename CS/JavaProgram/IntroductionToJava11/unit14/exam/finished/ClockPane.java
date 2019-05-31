package unit14.exam.out;

import java.util.Calendar;
import java.util.GregorianCalendar;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.text.Text;

public class ClockPane extends Pane {
    private int hour;
    private int minute;
    private int second;

    private double w = 250, h = 250;
    
    public ClockPane() {
        setCurrentTime();
    }

    public ClockPane(int hour, int minute, int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
        paintClock();
    }

    public int getHour() {
        return hour;
    }

    public void setHour(int hour) {
        this.hour = hour;
        paintClock();
    }

    public int getMinute() {
        return minute;
    }

    public void setMinute(int minute) {
        this.minute = minute;
        paintClock();
    }

    public int getSecond() {
        return second;
    }

    public void setSecond(int second) {
        this.hour = hour;
        paintClock();
    }

    public double getW() {
        return w;
    }

    public void setW(double w) {
        this.w = w;
        paintClock();
    }

    public double getH() {
        return h;
    }

    public void setH(double h) {
        this.h = h;
        paintClock();
    }

    public void setCurrentTime() {
        Calendar calendar = new GregorianCalendar();

        this.hour = calendar.get(Calendar.HOUR_OF_DAY);
        this.minute = calendar.get(Calendar.MINUTE);
        this.second = calendar.get(Calendar.SECOND);

        paintClock();
    }

    protected void paintClock() {
        getChildren().clear();

        double clockRadius = Math.min(w, h) * 0.8 * 0.5;
        double centerX = w / 2;
        double centerY = h / 2;

        Circle circle = new Circle(centerX, centerY, clockRadius);
        circle.setFill(Color.WHITE);
        circle.setStroke(Color.BLACK);
        getChildren().add(circle);

        for(int i = 0; i <= 59; i++) {
            double dLength;
            double edX;
            double edY;
            double sdX;
            double sdY;
            if(i % 5 == 0) {
                dLength = clockRadius * 0.08;
                int num = i / 5 == 0 ? 12 : i / 5;
                String s = new Integer(num).toString();
                double x = centerX - 5 + clockRadius * 0.8 * Math.sin(i * (2 * Math.PI / 60));
                double y = centerY + 5 - clockRadius * 0.8 * Math.cos(i * (2 * Math.PI / 60));
                Text t = new Text(x, y, s);
                getChildren().add(t);
            }
            else 
                dLength = clockRadius * 0.04;
            edX = centerX + (clockRadius - dLength) * Math.sin(i * (2 * Math.PI / 60));
            edY = centerY - (clockRadius - dLength) * Math.cos(i * (2 * Math.PI / 60));
            sdX = centerX + clockRadius * Math.sin(i * (2 * Math.PI / 60));
            sdY = centerY - clockRadius * Math.cos(i * (2 * Math.PI / 60));
            Line dLine = new Line(sdX, sdY, edX, edY);
            dLine.setStroke(Color.BLACK);

            getChildren().add(dLine);
        }

        double sLength = clockRadius * 0.8;
        double secondX = centerX + sLength * Math.sin(second * (2 * Math.PI / 60));
        double secondY = centerY - sLength * Math.cos(second * (2 * Math.PI / 60));
        Line sLine = new Line(centerX, centerY, secondX, secondY);
        sLine.setStroke(Color.RED);

        double mLength = clockRadius * 0.65;
        double minuteX = centerX + mLength * Math.sin((minute + second / 60.0)* (2 * Math.PI / 60));
        double minuteY = centerY - mLength * Math.cos((minute + second / 60.0)* (2 * Math.PI / 60));
        Line mLine = new Line(centerX, centerY, minuteX, minuteY);
        mLine.setStroke(Color.BLUE);

        double hLength = clockRadius * 0.5;
        double hourX = centerX + hLength * Math.sin((hour % 12 + minute / 60.0 + second / 3600.0) * (2 * Math.PI / 12));
        double hourY = centerY - hLength * Math.cos((hour % 12 + minute / 60.0 + second / 3600.0) * (2 * Math.PI / 12));
        Line hLine = new Line(centerX, centerY, hourX, hourY);
        hLine.setStroke(Color.GREEN);

        getChildren().addAll(sLine, mLine, hLine);
    }
}

