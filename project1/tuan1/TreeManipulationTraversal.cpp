
#include<bits/stdc++.h>
using namespace std;
// build tree
class Node {
    public : 
        int value;
        Node* leftMostChild;
        Node* rightSibling;
    public : 
        Node(int value) : value(value), leftMostChild(nullptr), rightSibling(nullptr) {}
};

typedef Node* Tree;
Tree root;

void insertNode(Tree& root, Node* p, int des) {
    if (root != NULL) {
        if (root->value == des) {
            Node* node = root->leftMostChild;
            // node = node->rightSibling;
            if (root->leftMostChild == NULL) {
                root->leftMostChild = p;
            } else {
                while (node->rightSibling != NULL) {
                    // cout << (node->value);
                    node = node->rightSibling;
                }
                node->rightSibling = p;
            }
            
        }else {
            insertNode(root->leftMostChild, p, des);
            insertNode(root->rightSibling, p, des);
        }
    }
    
}
void preOrder(Node* node) {
    if (node != NULL) {
        cout << node->value << " ";
        if (node->leftMostChild != NULL) {
            preOrder(node->leftMostChild);
            Node* p = node->leftMostChild->rightSibling;
            while(p != NULL) {
                preOrder(p);
                p = p->rightSibling;
            }
        }
    }
}   
void inOrder(Node* node) {

    if (node != NULL) {
        if (node->leftMostChild != NULL) inOrder(node->leftMostChild);
        cout << node->value << " ";
        if (node->leftMostChild != NULL) {
            Node* p = node->leftMostChild->rightSibling;
            while (p != NULL) {
                inOrder(p);
                p = p->rightSibling;
            } 
        }
        
    }
    // left-root-right
}
void posOrder(Node* node) {
    if (node != NULL) {
        if (node->leftMostChild != NULL) posOrder(node->leftMostChild);
        
        if (node->leftMostChild != NULL) {
            Node* p = node->leftMostChild->rightSibling;
            while(p != NULL) {
                posOrder(p);
                p = p->rightSibling;
            }
        }
        cout << node->value << " ";
    }
}

// make node, destroy node, insert tree, delete from tree, duyet tree
int main() {   
    string query;
    int a, b;
    set<int> s;
    while (cin >> query) {
        if (query == "MakeRoot") {
            cin >> a;
            s.insert(a);
            root = new Node(a);
        } else if (query == "Insert") {
            cin >> a >> b;
            if (s.find(b) != s.end()) {
                s.insert(a);
                Node* p = new Node(a);
                insertNode(root, p, b);
            }
        } else if (query == "PreOrder") {
            preOrder(root);
            cout << endl;
        } else if (query == "InOrder") {
            inOrder(root);
            cout << endl;
        } else if (query == "PostOrder") {
            posOrder(root);
            cout << endl;
        } else {
            break;
        }
    }
}