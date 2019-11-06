package unit10.exam.out;

public class Exam10 {
    
    public static void main(String[] args) {
        Queue q = new Queue();
        for(int i = 0; i < 21; i++)
            q.enqueue(i);

        while(!q.empty()) {
            System.out.println(q.dequeue());
        }
    }
}

class Queue {
    private int[] element;
    private int size;
    private int maxSize;
    private int front;

    public void Exam10() {
        maxSize = 8;
        element = new int[maxSize];
        size = 0;
        front = 0;
    }

    private void bigger() {
        int tmpSize = 2 * maxSize;
        int[] tmpElement = new int[tmpSize];
        for(int i = 0; i < maxSize; i++)
            tmpElement[i] = element[i];
        element = tmpElement;
        maxSize = tmpSize;
    }

    public void enqueue(int v) {
        if(size + 1 > maxSize)
            bigger();
        
        System.out.println((front + size) % maxSize);
        element[(front + size) % maxSize] = v;
        size++;
    }

    public int dequeue() {
        if(empty())
            return -1;

        int tmp = element[front];
        front = (front + 1) % maxSize;
        return tmp;
    }

    public boolean empty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }
}

