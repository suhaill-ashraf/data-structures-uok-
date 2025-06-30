#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* first;
    Node* last;

public:
    CircularLinkedList() {
        first = last = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!first) {
            first = last = newNode;
            last->next = first;
        } else {
            last->next = newNode;
            last = newNode;
            last->next = first;
        }
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!first) {
            first = last = newNode;
            last->next = first;
        } else {
            newNode->next = first;
            first = newNode;
            last->next = first;
        }
    }

    void deleteNode(int val) {
        if (!first) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = first;
        Node* prev = last;
        bool found = false;

        do {
            if (curr->data == val) {
                found = true;
                if (first == last && curr == first) { // Only one node
                    delete curr;
                    first = last = nullptr;
                } else if (curr == first) {
                    first = first->next;
                    last->next = first;
                    delete curr;
                } else if (curr == last) {
                    prev->next = first;
                    last = prev;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                cout << "Node deleted\n";
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != first);

        if (!found)
            cout << "Node not found\n";
    }

    void display() {
        if (!first) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = first;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val;

    do {
        cout << "\n----- Circular Linked List Menu -----\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Delete Node\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                cll.deleteNode(val);
                break;
            case 4:
                cll.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}