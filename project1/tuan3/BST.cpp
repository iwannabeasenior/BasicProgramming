#include<bits/stdc++.h>
using namespace std;
class Node {
    public: 
        int value;
        Node* left;
        Node* right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {};
};
void insert(Node* &root, Node* p) {
    if (root != nullptr) {
        if (root->value < p->value) {
            insert(root->right, p);
        } else if (root->value > p->value) {
            insert(root->left, p);
        }
    }
    else {
        root = p;
    }
}
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->value <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

int main() {
    Node* root = nullptr;
    string query;
    int value;
    set<int> s;
    int k = 0;
    int count = 0;
    while (cin >> query) {
        if (query == "insert") {
            cin >> value;
            if (s.find(value) == s.end()) {
                Node* p = new Node(value);
                insert(root, p);
                s.insert(value);
            }
        }
        else {
            break;
        }
    }
    preOrder(root);
}