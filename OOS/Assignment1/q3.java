class Stack {
    int[] stackArray;  
    int top;           
    public Stack(int size) {
        stackArray = new int[size];
        top = -1;  
    }
    public void push(int value) {
        if (top < stackArray.length - 1) {
            stackArray[++top] = value;
        } else {
            System.out.println("Stack Overflow! Unable to push " + value);
        }
    }
    public void pop() {
        if (top >= 0) {
            System.out.println("Popped: " + stackArray[top--]);  // Decrement top and remove the element
        } else {
            System.out.println("Stack Underflow! Unable to pop.");
        }
    }
    public void print() {
        if (top >= 0) {
            System.out.print("Stack: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(stackArray[i] + " ");
            }
            System.out.println();
        } else {
            System.out.println("Stack is empty.");
        }
    }
}


public class q3 {
    public static void main(String[] args) {
        Stack stack = new Stack(30);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(15);
        stack.push(9);
        stack.print();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.print();
    }
}

