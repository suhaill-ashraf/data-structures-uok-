#include <iostream>
using namespace std;

const int M = 4; // Max children per node
const int MAX_KEYS = M - 1;

struct MWayNode {
    int keys[MAX_KEYS];              // Up to M-1 keys
    MWayNode* children[M];           // M children
    int numKeys;                     // Current number of keys
    bool isLeaf;

    MWayNode() {
        numKeys = 0;
        isLeaf = true;
        for (int i = 0; i < M; ++i)
            children[i] = nullptr;
    }
};

class MWayTree {
    MWayNode* root;

public:
    MWayTree() {
        root = new MWayNode();
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    bool search(int key) {
        return searchRec(root, key);
    }

private:
    MWayNode* insertRec(MWayNode* node, int key) {
        int i;
        for (i = 0; i < node->numKeys && key > node->keys[i]; i++);

        // If key already exists
        if (i < node->numKeys && node->keys[i] == key) {
            cout << "Duplicate key not allowed!\n";
            return node;
        }

        if (node->isLeaf) {
            if (node->numKeys < MAX_KEYS) {
                for (int j = node->numKeys; j > i; j--)
                    node->keys[j] = node->keys[j - 1];
                node->keys[i] = key;
                node->numKeys++;
            } else {
                cout << "Node full! No balancing implemented.\n";
            }
        } else {
            node->children[i] = insertRec(node->children[i], key);
        }
        return node;
    }

    void inorderRec(MWayNode* node) {
        if (!node) return;

        for (int i = 0; i < node->numKeys; i++) {
            inorderRec(node->children[i]);
            cout << node->keys[i] << " ";
        }
        inorderRec(node->children[node->numKeys]);
    }

    bool searchRec(MWayNode* node, int key) {
        if (!node) return false;

        int i;
        for (i = 0; i < node->numKeys && key > node->keys[i]; i++);

        if (i < node->numKeys && key == node->keys[i])
            return true;

        return searchRec(node->children[i], key);
    }
};

int main() {
    MWayTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "In-order Traversal of M-way tree: ";
    tree.inorder();

    int searchKey = 25;
    cout << "Search " << searchKey << ": "
         << (tree.search(searchKey) ? "Found" : "Not Found") << endl;

    return 0;
}
