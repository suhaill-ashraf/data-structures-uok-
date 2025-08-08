#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BPlusNode {
public:
    bool isLeaf;
    vector<int> keys;
    vector<BPlusNode*> children;
    BPlusNode* next;

    BPlusNode(bool leaf = true) {
        isLeaf = leaf;
        next = nullptr;
    }
};

class BPlusTree {
    BPlusNode* root;
    int t;

public:
    BPlusTree(int _t) {
        root = new BPlusNode(true);
        t = _t;
    }

    void insert(int key);
    void display();
};

void BPlusTree::insert(int key) {
    root->keys.push_back(key);
    sort(root->keys.begin(), root->keys.end());
}

void BPlusTree::display() {
    BPlusNode* temp = root;
    cout << "Leaf nodes: ";
    for (int k : temp->keys)
        cout << k << " ";
    cout << endl;
}

int main() {
    BPlusTree bpt(3);

    bpt.insert(5);
    bpt.insert(15);
    bpt.insert(25);
    bpt.insert(35);
    bpt.insert(45);

    bpt.display();

    return 0;
}
