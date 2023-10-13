#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// c1 : de quy
class Solution {
public:
    int flag = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x;
        
        if (l1 == NULL && l2 == NULL){
            if (flag){
                return new ListNode(1);
            }
            return NULL;
        }

        if (l1 == NULL){
            l2->val = l2->val + flag;
            flag = l2->val / 10;
            l1 = new ListNode(l2->val % 10);
            l1->next = addTwoNumbers(l1->next, l2->next);
            return l1;
        }

        if (l2 == NULL){
            ListNode* ln = l1;
            ListNode* ln2;
            while(ln){
                int mid = ln->val + flag;
                flag = mid / 10;
                ln->val = mid % 10;
                ln2 = ln;
                ln = ln->next;
            }
            if (flag){
                ln2->next = new ListNode(1);
            }
            return l1;
        }
       
        x = l1->val + l2->val + flag;
        flag = x / 10;
        l1->val = x % 10;
        l1->next = addTwoNumbers(l1->next, l2->next);
        return l1;
    }
};

// c2 : khong de quy
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};
int main(){

}