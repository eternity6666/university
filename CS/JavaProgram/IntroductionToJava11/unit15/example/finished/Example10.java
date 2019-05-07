// ObservablePropertyDemo.java

package unit15.example.out;

import javafx.beans.InvalidationListener;
import javafx.beans.Observable;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;

public class Example10 {
    public static void main(String[] args) {
        DoubleProperty balance = new SimpleDoubleProperty();
        /*
        balance.addListener(new InvalidationListener() {
            public void invalidated(Observable ov) {
                System.out.println("The new value is " + balance.doubleValue());
            }
        });
        */
        // 使用lambda表达式简化
        balance.addListener(ov -> {
            System.out.println("The new value is " + balance.doubleValue());
        });

        balance.set(4.5);
    }    
}

