#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

// Create a new node
Node* createNode(int key) {
    Node* temp = new Node;
    temp->data = key;
    temp->lthread = temp->rthread = true;
    temp->left = temp->right = nullptr;
    return temp;
}

// Insert a node in threaded binary tree
Node* insert(Node* root, int key) {
    Node* ptr = root;
    Node* parent = nullptr;

    while (ptr != nullptr) {
        if (key == ptr->data) {
            cout << "Duplicate key!" << endl;
            return root;
        }
        parent = ptr;
        if (key < ptr->data) {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        } else {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* newNode = createNode(key);

    if (parent == nullptr) {
        root = newNode;
    } else if (key < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->lthread = false;
        parent->left = newNode;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rthread = false;
        parent->right = newNode;
    }

    return root;
}

// In-order traversal without recursion or stack
void inorder(Node* root) {
    if (!root) return;

    Node* ptr = root;
    while (!ptr->lthread)
        ptr = ptr->left;

    while (ptr != nullptr) {
        cout << ptr->data << " ";

        if (ptr->rthread)
            ptr = ptr->right;
        else {
            ptr = ptr->right;
            while (ptr && !ptr->lthread)
                ptr = ptr->left;
        }
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal of threaded binary tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
