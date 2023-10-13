#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        auto len = 1;
        auto tale = head;
        auto tg = head;
        // tg = tale right now, tg la trung gian
        while (tale->next != nullptr) {
            tale = tale->next;
            len++;
        }
        if (k%len == 0) return head;
        for (auto i = 0; i < len-k%len - 1; i++) {
            tg = tg->next;
        }
        
        tale->next = head;
        head = tg->next;
        tg->next = nullptr;
        return head;
    }
};