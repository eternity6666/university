public class example07 {
    public static void main(String[] args) {
        example08 stack = new example08(100);

        for(int i = 0; i < 10; i++)
            stack.push(i);

        while(!stack.empty())
            System.out.print(stack.pop() + " ");
        System.out.println();
    }
}

