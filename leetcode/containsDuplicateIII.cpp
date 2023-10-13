#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
       
        int n = nums.size();
        if (indexDiff >= n-1){
            indexDiff = n-1;
        }

        vector<int> nums2{nums.begin(), nums.begin() + indexDiff+1};
        sort(nums2.begin(), nums2.end());
        for (int i=0; i<indexDiff; i++){
            if (nums2[i+1] - nums2[i] <= valueDiff) {
                return true;
            }
        }

        int t = n - 1 - indexDiff;
        int k = 1;

        while(t){
            for (int i=k; i<indexDiff+k; i++){
                if (abs(nums[indexDiff + k] - nums[i]) <= valueDiff)
                {
                    return true;
                } 
            }
            k++;
            t--;
        }
        return false;
    }
};



// c2 : use set 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window; 
        for (int i=0; i<nums.size(); i++){
            if (i > indexDiff){
                window.erase(nums[i-indexDiff-1]);
            }
            // valueDiff >= |nums[i] - x| -> -valueDiff <= nums[i] - x <= valueDiff
            auto pos = window.lower_bound(nums[i] - valueDiff); // x >= nums[i] - valueDiff 
            // chọn lower_bound(tức là x nhỏ nhất thỏa mãn) vì : nếu x nhỏ nhất ko thỏa mãn đk bên dưới thì x lớn hơn cũng sẽ ko thỏa mãn điều kiện bên dưới được
            if (pos != window.end() && (*pos <= nums[i] + valueDiff)){ // x <= nums[i] + valueDiff
                return true;
            }
            window.insert(nums[i]);
        }
    }
};

int main(){
    vector<int> nums{1,5,9,1,5,9};
    Solution s = Solution();
    cout << s.containsNearbyAlmostDuplicate(nums, 2, 3);
}