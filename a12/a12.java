import java.util.*;

abstract class Stack {
    abstract void push();

    abstract void pop();

    abstract void display();
}

class StackException extends Exception {
    public StackException(String s) {
        super(s);
    }
}

class IntegerStack extends Stack {
    int[] stack;
    int top;

    IntegerStack() {
        stack = new int[10];
        top = -1;
    }

    void push() {
        try {
            if (top == 9) {
                throw new StackException("Error");
            } else {
                Scanner in = new Scanner(System.in);
                System.out.println("Enter the number");
                int temp = in.nextInt();
                stack[++top] = temp;
            }
        } catch (StackException e) {
            System.out.println("Stack is full!");
        }
    }

    void pop() {
        try {
            if (top == -1) {
                throw new StackException("Error");
            } else {
                System.out.println("Popped number is " + stack[top--]);
            }
        } catch (StackException e) {
            System.out.println("Stack is empty!");
        }
    }

    void display() {
        for (int i = 0; i <= top; ++i) {
            System.out.print(stack[i] + " ");
        }
        System.out.println("");
    }
}

class CharStack extends Stack {
    char[] stack;
    int top;

    CharStack() {
        stack = new char[10];
        top = -1;
    }

    void push() {
        try {
            if (top == 9) {
                throw new StackException("Error");
            } else {
                Scanner in = new Scanner(System.in);
                System.out.println("Enter the character");
                char temp = in.next().charAt(0);
                stack[++top] = temp;
            }
        } catch (StackException e) {
            System.out.println("Stack is full!");
        }
    }

    void pop() {
        try {
            if (top == -1) {
                throw new StackException("Error");
            } else {
                System.out.println("Popped character is " + stack[top--]);
            }
        } catch (StackException e) {
            System.out.println("Stack is empty!");
        }
    }

    void display() {
        for (int i = 0; i <= top; ++i) {
            System.out.print(stack[i] + " ");
        }
        System.out.println("");
    }
}

class Main {
    public static void main(String[] args) {
        Stack intObj = new IntegerStack();
        Stack charObj = new CharStack();
        int choice;
        Scanner in = new Scanner(System.in);
        do {
            System.out.println("Menu\n1) Integer Stack\n2) Character Stack\n3) Exit");
            System.out.println("Enter choice");
            choice = in.nextInt();
            if (choice == 1) {
                int ch;
                do {
                    System.out.println("Menu\n1) Push\n2) Pop\n3) Display\n4) Exit");
                    ch = in.nextInt();
                    switch (ch) {
                        case 1: {
                            intObj.push();
                            break;
                        }
                        case 2: {
                            intObj.pop();
                            break;
                        }
                        case 3: {
                            intObj.display();
                            break;
                        }
                        case 4:
                            break;
                    }
                } while (ch != 4);
            } else if (choice == 2) {
                int ch;
                do {
                    System.out.println("Menu\n1) Push\n2) Pop\n3) Display\n4) Exit");
                    ch = in.nextInt();
                    switch (ch) {
                        case 1: {
                            charObj.push();
                            break;
                        }
                        case 2: {
                            charObj.pop();
                            break;
                        }
                        case 3: {
                            charObj.display();
                            break;
                        }
                        case 4:
                            break;
                    }
                } while (ch != 4);
            }
        } while (choice != 3);
    }
}