#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        
        stack<int> st;
        map<int, int> m;
        for (int i = 0; i < nums2.size(); i++) {
            if (st.empty()) st.push(nums2[i]);
            else{
                while (!st.empty() && nums2[i] > st.top()) {
                    m.insert({st.top(), nums2[i]});
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        while (!st.empty()) {
            m.insert({st.top(), -1});
            st.pop();
        }

        for (int a : nums1) {
            auto it = m.find(a);
            v.push_back(it->second);  
        }
        return v;
    }
};