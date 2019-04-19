package unit10.example.out;

import unit10.example.out.Example08;

public class Example07 {
    public static void main(String[] args) {
        Example08 stack = new Example08(100);

        for(int i = 0; i < 10; i++)
            stack.push(i);

        while(!stack.empty())
            System.out.print(stack.pop() + " ");
        System.out.println();
    }
}

