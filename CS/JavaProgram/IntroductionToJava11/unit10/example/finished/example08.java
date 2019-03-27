/* It is a class named Stack */

import java.util.Arrays;

public class example08 {
    private int[] elements;
    private int size;
    public static final int DEFAULT_CAPACITY = 16;

    public example08() {
        this(DEFAULT_CAPACITY);
    }
 
    public example08(int capacity) {
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
public class example08 {
    private int[] elements;
    private int size;
    
    public example08() {
        this(6);
    }

    public example08(int capacity) {
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

