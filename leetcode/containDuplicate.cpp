#include<bits/stdc++.h>
using namespace std;

//c1 : use set and sliding window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // i-j <= k
        set<int> window;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > k){
                window.erase(nums[i-k-1]);
            }
            auto t = window.lower_bound(nums[i]);
            if (t != window.end() && *t == nums[i]){
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

// c2 : unordered_map
class Solution { 
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> t ;
        for (int i=0; i<nums.size(); i++){
            auto it = t.find(nums[i]);
            if (it != t.end() && i - it->second <= k) return true;
            t[nums[i]] = i;
        }
    }
};
int main(){

}