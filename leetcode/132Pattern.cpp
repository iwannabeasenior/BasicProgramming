#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {    
        // duy tri 2
        //use monotonic stack
        stack<int> st;
        int s2 = INT_MIN;
        for (int i : nums) {
            if (i < s2) return true;
            else {
                while (!st.empty() && i > st.top()) {
                    s2 = st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return false;
    }
};