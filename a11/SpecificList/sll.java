package SpecificList;

import CommonList.CommonList;

import java.util.Scanner;

class Node {
    public int data;
    public Node next;

    public Node() {
        data = 0;
        next = null;
    }

}

class Operations implements CommonList {
    Node start;

    public Operations() {
        start = null;
    }

    public boolean isEmpty() {
        if (start == null) {
            return true;
        } else
            return false;
    }

    public void display() {
        System.out.println("The linked list is");
        Node temp = new Node();
        temp = start;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println("");
    }

    public void add(int data) {
        Node temp = new Node();
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
        if (start == null) {
            start = newNode;
            return;
        }
        temp = start;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void remove(int data) {

        Node currNode = new Node();
        Node prevNode = new Node();
        currNode = prevNode = start;
        if (start.data == data) {
            currNode = start;
            start = start.next;
            currNode.next = null;
            currNode = null;
        } else {
            while (currNode.data != data) {
                prevNode = currNode;
                currNode = currNode.next;
            }
            prevNode.next = currNode.next;
            currNode.next = null;
            currNode = null;
        }
    }

    public int size() {
        Node temp = new Node();
        temp = start;
        int size = 0;
        while (temp != null) {
            temp = temp.next;
            size++;
        }
        return size;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Operations list = new Operations();
        System.out.println("Menu:");
        int choice;
        do {
            System.out.println(
                    "\n1) Add Node\n2) Delete node\n3) Display list\n4) Display size\n5) Check if empty\n6) Exit");
            System.out.println("Enter your choice ");
            choice = input.nextInt();
            switch (choice) {
                case 1: {
                    int data;
                    System.out.println("Enter the number to be inserted ");
                    data = input.nextInt();
                    list.add(data);
                    System.out.println("Added " + data + " successfully!");
                    break;
                }
                case 2: {
                    if (list.isEmpty()) {
                        System.out.println("The list is empty!!");
                        break;
                    }
                    int data;
                    System.out.println("Enter the number to be deleted ");
                    data = input.nextInt();
                    list.remove(data);
                    System.out.println("Deleted " + data + " successfully!");
                    break;
                }
                case 3: {
                    if (list.isEmpty()) {
                        System.out.println("The list is empty!!");
                        break;
                    }
                    list.display();
                    break;
                }
                case 4: {
                    System.out.println("The size of the LL is " + list.size());
                    break;
                }
                case 5: {
                    if (list.isEmpty()) {
                        System.out.println("The linked list is empty!");
                    } else {
                        System.out.println("The linked list is not empty");
                    }
                }
                case 6:
                    break;
            }
        } while (choice != 6);
        input.close();
    }

}
