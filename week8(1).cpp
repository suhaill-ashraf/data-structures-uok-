#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued.\n";
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedQueue q;
    int choice, val;
    do {
        cout << "\n--- Linked List Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
