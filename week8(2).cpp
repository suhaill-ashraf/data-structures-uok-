#include <iostream>
using namespace std;

#define MAX 100

class MultiStack {
private:
    int arr[MAX];
    int top1, top2;

public:
    MultiStack() {
        top1 = -1;
        top2 = MAX;
    }

    void push1(int val) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow on Stack 1!\n";
            return;
        }
        arr[++top1] = val;
        cout << val << " pushed to Stack 1.\n";
    }

    void push2(int val) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow on Stack 2!\n";
            return;
        }
        arr[--top2] = val;
        cout << val << " pushed to Stack 2.\n";
    }

    void pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow!\n";
            return;
        }
        cout << arr[top1--] << " popped from Stack 1.\n";
    }

    void pop2() {
        if (top2 == MAX) {
            cout << "Stack 2 Underflow!\n";
            return;
        }
        cout << arr[top2++] << " popped from Stack 2.\n";
    }

    void display1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty.\n";
            return;
        }
        cout << "Stack 1: ";
        for (int i = top1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    void display2() {
        if (top2 == MAX) {
            cout << "Stack 2 is empty.\n";
            return;
        }
        cout << "Stack 2: ";
        for (int i = top2; i < MAX; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MultiStack ms;
    int choice, val;
    do {
        cout << "\n--- Multiple Stack Menu ---\n";
        cout << "1. Push to Stack 1\n2. Pop from Stack 1\n";
        cout << "3. Display Stack 1\n4. Push to Stack 2\n";
        cout << "5. Pop from Stack 2\n6. Display Stack 2\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; ms.push1(val); break;
            case 2: ms.pop1(); break;
            case 3: ms.display1(); break;
            case 4: cout << "Enter value: "; cin >> val; ms.push2(val); break;
            case 5: ms.pop2(); break;
            case 6: ms.display2(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
