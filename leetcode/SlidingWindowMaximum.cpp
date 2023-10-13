#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> window;
        vector<int> vmax;
        for (int i=0; i<k; i++){
            window.insert(nums[i]);
        }
        auto it = --window.end();
        vmax.push_back(*it);

        for (int i=k; i<n; i++){
            auto it1 = window.find(nums[i-k]);
            window.erase(it1);
            window.insert(nums[i]);
            auto it = --window.end();
            vmax.push_back(*it);
        }
        return vmax;
    }
};

// priority_queue
class Solution {
public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<int> v;
        v.push_back(pq.top().first);
        
        for (int i = k; i < n; i++){
            pq.push(make_pair(nums[i],i));
            while (i - pq.top().second >= k) pq.pop();
            pq.push(pq.top().first);
        }
        return v;     
    }
};
int main(){

}