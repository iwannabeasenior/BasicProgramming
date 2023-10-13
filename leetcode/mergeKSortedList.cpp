#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// c1 : vector
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();

        if (lists.empty()){
            return nullptr;
        }
        
        while (lists.size() > 1){
            lists.push_back((lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    ListNode* mergeTwoList(ListNode* x, ListNode* y){
        // use merge sort 
        if (x == NULL){
            return y;
        }
        if (y == NULL){
            return x;
        }
        if (x -> val < y -> val){
            x -> next = mergeTwoList(x->next, y);
            return x;
        }
        else {
            y->next = mergeTwoList(x, y->next);
            return y;
        }
    }
};

// c2 : priority_queue
class Solution{
public : 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++){
            ListNode* l = lists[i];
            while (l != NULL){
                pq.push(l->val);
                l = l->next;
            }
        }
        if (pq.empty()) return nullptr;
        
        ListNode* head = new ListNode(pq.top());
        ListNode* curr = head;
        pq.pop();
        while (!pq.empty()){
            int x = pq.top();
            pq.pop();
            ListNode* newnode = new ListNode(x);
            head->next = newnode;
            head = head->next;
        }
        return curr;
    }
};

// c3 : heap 
class Solution {
public :
    static bool heapComp(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        int n = lists.size();
        ListNode head(0);
        ListNode *curNode = &head;
        vector<ListNode*> v;
        for (int i = 0; i < n; i++){
            if (lists[i]){
                v.push_back(lists[i]);
            }
        }
        // make heap 
        make_heap(v.begin(), v.end(), heapComp);
        while (v.size() > 0){
            curNode->next = v.front();
            // dua phan tu dau tien ve cuoi day roi heap n-1 phan tu dau tien
            pop_heap(v.begin(), v.end(), heapComp);
            v.pop_back();
            curNode = curNode->next;
            if (curNode->next){
                v.push_back(curNode->next);
                // make lai heap sau khi push back
                push_heap(v.begin(), v.end(), heapComp); 
            }
        }
        return head.next;
    }      
};
