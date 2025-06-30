#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int top;
    int data[MAX];

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int val) {
        if (top == MAX - 1) return;
        data[++top] = val;
    }

    int pop() {
        if (isEmpty()) return -1;
        return data[top--];
    }
};

class QuickSortStack {
private:
    int arr[MAX], n;

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            }
        }
        int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
        return i + 1;
    }

public:
    void inputArray() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void sort() {
        Stack lStack, hStack;
        lStack.push(0);
        hStack.push(n - 1);

        while (!lStack.isEmpty()) {
            int high = hStack.pop();
            int low = lStack.pop();

            int p = partition(low, high);

            if (p - 1 > low) {
                lStack.push(low);
                hStack.push(p - 1);
            }
            if (p + 1 < high) {
                lStack.push(p + 1);
                hStack.push(high);
            }
        }

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QuickSortStack q;
    int choice;
    do {
        cout << "\n--- Stack-Based QuickSort Menu ---\n";
        cout << "1. Enter Array\n2. Sort\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: q.inputArray(); break;
            case 2: q.sort(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);
    return 0;
}
