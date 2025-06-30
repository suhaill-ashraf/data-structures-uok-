#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int arr[MAX], front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(int val) {
        if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = rear = 0;
        else if (rear == MAX - 1) rear = 0;
        else rear++;
        arr[rear] = val;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) front = rear = -1;
        else if (front == MAX - 1) front = 0;
        else front++;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        if (front <= rear) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < MAX; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cq.display(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
