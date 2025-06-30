#include <iostream>
using namespace std;

// Polynomial Node
class PolyNode {
public:
    int coeff, power;
    PolyNode* next;

    PolyNode(int c, int p) {
        coeff = c;
        power = p;
        next = nullptr;
    }
};

// Polynomial Class
class Polynomial {
public:
    PolyNode* head;

    Polynomial() {
        head = nullptr;
    }

    void insertTerm(int coeff, int power) {
        PolyNode* newNode = new PolyNode(coeff, power);
        if (!head || head->power < power) {
            newNode->next = head;
            head = newNode;
        } else {
            PolyNode* temp = head;
            while (temp->next && temp->next->power > power)
                temp = temp->next;

            if (temp->power == power) {
                temp->coeff += coeff;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void display() {
        PolyNode* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->power;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        PolyNode *a = p1.head, *b = p2.head;

        while (a && b) {
            if (a->power > b->power) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (a->power < b->power) {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            } else {
                result.insertTerm(a->coeff + b->coeff, a->power);
                a = a->next;
                b = b->next;
            }
        }

        while (a) {
            result.insertTerm(a->coeff, a->power);
            a = a->next;
        }

        while (b) {
            result.insertTerm(b->coeff, b->power);
            b = b->next;
        }

        return result;
    }

    static Polynomial multiply(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        for (PolyNode* a = p1.head; a; a = a->next) {
            for (PolyNode* b = p2.head; b; b = b->next) {
                result.insertTerm(a->coeff * b->coeff, a->power + b->power);
            }
        }
        return result;
    }
};

// Doubly Linked List Node
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Doubly Linked List Class
class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtStart(int val) {
        DNode* newNode = new DNode(val);
        if (head) head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfterElement(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Element not found.\n";
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found.\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main Menu
int main() {
    Polynomial p1, p2, result;
    DoublyLinkedList dll;
    int choice;

    do {
        cout << "\n--- Week 4 Menu ---\n";
        cout << "1. Insert term in Polynomial 1\n";
        cout << "2. Insert term in Polynomial 2\n";
        cout << "3. Add polynomials\n";
        cout << "4. Multiply polynomials\n";
        cout << "5. Display Polynomial 1\n";
        cout << "6. Display Polynomial 2\n";
        cout << "7. Display Result Polynomial\n";
        cout << "8. Insert in DLL (start)\n";
        cout << "9. Insert in DLL (end)\n";
        cout << "10. Insert in DLL (after element)\n";
        cout << "11. Delete from DLL\n";
        cout << "12. Display DLL\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int coeff, power, val, key;

        switch (choice) {
        case 1:
            cout << "Enter coefficient and power: ";
            cin >> coeff >> power;
            p1.insertTerm(coeff, power);
            break;
        case 2:
            cout << "Enter coefficient and power: ";
            cin >> coeff >> power;
            p2.insertTerm(coeff, power);
            break;
        case 3:
            result = Polynomial::add(p1, p2);
            cout << "Polynomials added.\n";
            break;
        case 4:
            result = Polynomial::multiply(p1, p2);
            cout << "Polynomials multiplied.\n";
            break;
        case 5:
            cout << "Polynomial 1: ";
            p1.display();
            break;
        case 6:
            cout << "Polynomial 2: ";
            p2.display();
            break;
        case 7:
            cout << "Result Polynomial: ";
            result.display();
            break;
        case 8:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtStart(val);
            break;
        case 9:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtEnd(val);
            break;
        case 10:
            cout << "Insert after which element? ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            dll.insertAfterElement(key, val);
            break;
        case 11:
            cout << "Enter value to delete: ";
            cin >> key;
            dll.deleteNode(key);
            break;
        case 12:
            cout << "Doubly Linked List: ";
            dll.display();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
