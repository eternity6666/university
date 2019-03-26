// MyStack.java
package unit11.example.out;

import java.util.ArrayList;

public class Example10 {
    private ArrayList<Object> list = new ArrayList<>();

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public int getSize() {
        return list.size();
    }

    public Object top() {
        return list.get(getSize() - 1);
    }

    public Object top() {
        Object o = peek();
        list.remove(getSize() - 1);
        return o;
    }

    public void push(Object o) {
        list.add(o);
    }

    @Override
    public String toString() {
        return "stacks: " + list.toString();
    }
}

