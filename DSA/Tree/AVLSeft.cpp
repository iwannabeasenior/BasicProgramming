#include <bits/stdc++.h>

typedef struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {};
    Node(int x) : val(x), left(nullptr), right(nullptr) {};
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {};
}Node;

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node *root) {
    if (root == nullptr) return 0;
    else return 1 + max(getHeight(root->left), getHeight(root->right));
}
Node* insertNode(Node *root, int x) { 
    if (root == nullptr) root = new Node(x);
    else if (root->val > x) {
        insertNode(root->left, x);
    }
    else if (root->val < x) {
        insertNode(root->right, x);
    }
    else return root;
    // set balanced tree
    
    
}
int main() {
}