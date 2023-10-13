#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        // i  : hien tai
        // nums[0] 1 -> nums[0] : nums[0 + i] + i : max :    
        int n = nums.size();
        int curr = 0;
        int chiso = 0;
        int sobuoc = 0;
        if (nums[0] == 0) return 0;
        if (n == 1) return 0; 
        while(curr + nums[curr] < n-1){
            int max = 0;
            for (int k = 1; k <= nums[curr]; k++){
                if (nums[curr + k] + k > max && nums[curr + k] != 0){
                    max = nums[curr + k] + k;
                    chiso = k;
                }
            } 
            sobuoc++;
            curr += chiso;
        }
        return sobuoc + 1;
    }
};
int main (){
    
}