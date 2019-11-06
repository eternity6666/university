/* It is a class named Stack */
package unit10.example.out;

import java.util.Arrays;

public class Example08 {
    private int[] elements;
    private int size;
    public static final int DEFAULT_CAPACITY = 16;

    public Example08() {
        this(DEFAULT_CAPACITY);
    }
 
    public Example08(int capacity) {
        elements = new int[capacity];
    }

    public boolean empty() {
        return size == 0;
    }

    public void push(int element) {
        if(size >= elements.length) {
            int[] temp = new int[elements.length * 2];
            System.arraycopy(elements, 0, temp, 0, elements.length);
            elements = temp;
        }

        elements[size++] = element;
    }

    public int pop() {
        return elements[--size];
    }

    public int peek() {
        return elements[size - 1];
    }

    public int getSize() {
        return size;
    }
}

/*
public class Example08 {
    private int[] elements;
    private int size;
    
    public Example08() {
        this(6);
    }

    public Example08(int capacity) {
        elements = new int[capacity];
    }

    public boolean empty() {
        return size == 0;
    }

    public int top() {
        // if(!empty())
        return elements[size - 1];
    }

    public void push(int element) {
        if(size != elements.length) { 
            elements[size] = element;
            size++;
        }
        else
            System.out.println("Error");
    }

    public int pop() {
        size--;
        return elements[size];
    }

    public int getSize() {
        return size;
    }
}
*/

