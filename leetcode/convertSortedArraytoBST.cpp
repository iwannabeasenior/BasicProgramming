#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return nullptr;
        else if (len == 1) return new TreeNode(nums[0]);

        int mid = nums.size()/2;
        TreeNode *newNode = new TreeNode(nums[mid]);
        vector<int> nums1;
        for (int i = 0; i < mid; i++) {
            nums1.push_back(nums[i]);
        }
        vector<int> nums2;
        for (int i = mid + 1; i < len; i++)
        {
            nums2.push_back(nums[i]);
        }
         
        newNode->left = sortedArrayToBST(nums1);
        newNode->right = sortedArrayToBST(nums2);
        return newNode;
    }
};
int main() {

}