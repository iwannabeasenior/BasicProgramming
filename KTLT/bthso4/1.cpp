#include <iostream> 
using namespace std;
//Nguyen Trung Thanh - 20215482
struct Node { 
    int data; 
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node* node = new(Node)(data);
    Node node2(data);
    if (head == NULL){
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
    return head;
}

// print the list content on a line
void print(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if(head == NULL){
        return;
    }
    for (Node* node = head; node != NULL;node = node -> next){
         cout << node->data << " \n"[node -> next == NULL];
    }
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
     Node* prev = head;
    Node* current = head->next;
    Node* next = current->next;
    if (next == NULL){
        current->next = prev;
        head->next = NULL;
        head = current;
        return head;
    }
    while(next != NULL){
        current->next = prev;
        prev = current;
        current = next;
        next = next->next;
    }
    current->next = prev;
    head->next = NULL;
    head = current;
    return head;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}