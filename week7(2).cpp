#include <iostream>
using namespace std;

#define MAX 100

class LinearQueue {
private:
    int arr[MAX], front, rear;

public:
    LinearQueue() {
        front = rear = -1;
    }

    void enqueue(int val) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << val << " enqueued.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front++] << " dequeued.\n";
        if (front > rear) front = rear = -1;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    LinearQueue q;
    int choice, val;

    do {
        cout << "\n--- Linear Queue Menu ---\n";
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
