#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfterElement(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Element not found.\n";
        return;
    }
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int pos, int val) {
    if (pos == 0) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Position out of bounds.\n";
        return;
    }
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Element not found.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void reverseList() {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display() {
    Node* temp = head;
    if (!temp) {
        cout << "List is empty.\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, val, pos, key;
    do {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After Element\n4. Insert at Position\n";
        cout << "5. Delete Node by Value\n6. Reverse List\n7. Display List\n8. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(val); break;
        case 2: cout << "Enter value: "; cin >> val; insertAtEnd(val); break;
        case 3: cout << "Enter existing element: "; cin >> key; cout << "Enter value to insert: "; cin >> val; insertAfterElement(key, val); break;
        case 4: cout << "Enter position: "; cin >> pos; cout << "Enter value: "; cin >> val; insertAtPosition(pos, val); break;
        case 5: cout << "Enter value to delete: "; cin >> key; deleteByValue(key); break;
        case 6: reverseList(); break;
        case 7: display(); break;
        }
    } while (choice != 8);
    return 0;
}
