#include<bits/stdc++.h>
using namespace std;
class Node {
    public: 
        int value;
        Node* next;
        Node(int value) : value(value), next(nullptr) {};
        Node(){};
};

class List { 
    public : 
    Node* first;
    Node* last;
};
List lis;
void initList() {
    lis.first = NULL;
    lis.last = NULL;
}
Node* findKey(int u) {
    Node* a = lis.first;
    while (a != lis.last) {
        if (a->value == u) {
            return a;
        } else {
            a = a->next;
        }
    }
    if (lis.last->value == u) {
        return lis.last;
    }
}
// insert first, insert last, insert random
void addLast(Node* p) {
    if (lis.first == nullptr) {
        lis.first = p;
        lis.last = p;
    } else {
        lis.last->next = p;
        lis.last = p;
    }
}
void addfirst(Node* p) {
    p->next = lis.first;
    lis.first = p;
}
void addafter(Node* p, int v) {
    if (lis.last->value == v) {
        addLast(p);
    } else {
        Node* a = findKey(v);
        p->next = a->next;
        a->next = p;
        
    }
   
    
}
void addbefore(Node* p, int v) {
    Node* q = new Node();
    if (lis.first->value == v) {
        addfirst(p);
    } else {
       for (Node* k = lis.first; k != nullptr; k = k->next) {
            if (k->value == v) {
                q->next = p;
                p->next = k;
                return;     
            } 
            q = k;
        } 
    }
    
}

// remove
void removeFirst() {
    Node* p = new Node();
    p = lis.first;
    lis.first = lis.first->next;
    p->next = NULL;
    delete p;
}
void removeLast() {
    // if (lis.first == lis.last) {
    //     removeFirst();
    // }
    // else {
        for (Node* k = lis.first; k != NULL; k = k->next) {
            if (k->next == lis.last) {
                delete lis.last;
                k->next = NULL;
                lis.last = k;
                return;
            }
        }
    // }
    
}
void remove(int u) {
    Node* p = new Node();
    if (u == lis.first->value) {
        removeFirst();
    } else if (u == lis.last->value) {
        removeLast();
    } else {
        // for (Node* k = lis.first; k != nullptr; k = k->next) {
        //     if (k->next->value == u) {
        //         Node* p = k->next;
        //         k = k->next->next;
        //         p->next = NULL;
        //         delete p;
        //     }
        // }
        for(Node* k = lis.first; k != NULL; k = k->next){
		if(k->value == u){
			p->next = k->next;
			delete k;
			return;
		}
		p = k;
	}
    }
}
void reverse() {
    if(lis.first == NULL){
        return;
    }
    if(lis.first->next == NULL){
        return ;
    }
    Node* prev = lis.first;
    Node* current = lis.first->next;
    Node* next = current->next;
    if (next == NULL){
        current->next = prev;
        lis.first->next = NULL;
        lis.last = lis.first;
        lis.first = current;
        return;
    }
    while (next != NULL){
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    current->next = prev;
    lis.first->next = NULL;
    lis.last = lis.first;
    lis.first = current;
    return;
}
int main() {
    int n; cin >> n;
    int value;
    initList();
    set<int> s;
    for (int i = 0; i < n; i++)
    {   
        cin >> value;
        s.insert(value);
        Node* p = new Node(value);
        addLast(p);
    }
    string query;
    int a, b;
    while (cin >> query) {
        if (query == "addlast") {
            cin >> a;
            if (s.find(a) == s.end()) {
                addLast(new Node(a));
                s.insert(a);
            }
        } else if (query == "addfirst") {
            cin >> a;
            if (s.find(a) == s.end()) {
                addfirst(new Node(a));
                s.insert(a);
            }
        } else if (query == "addafter") {
            cin >> a >> b;
            if (s.find(a) == s.end() && s.find(b) != s.end()) {
                addafter(new Node(a), b);
                s.insert(a);
            }
        } else if (query == "addbefore") {
            cin >> a >> b;
            if (s.find(a) == s.end() && s.find(b) != s.end()) {
                addbefore(new Node(a), b);
                s.insert(a);
            }
        } else if (query == "remove") {
            cin >> a;
            set<int> :: iterator it;
            if (s.find(a) != s.end()) {
               it = s.find(a);
               s.erase(it);
               remove(a); 

            }
            
        } else if (query == "reverse") {
            reverse();
        } else {
            break;
        }
    
    }
    for (Node* k = lis.first; k != lis.last; k = k->next) {
        cout << k->value << " ";
    }
    cout << lis.last->value;
}