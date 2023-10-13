#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // int sum = 0;
    // vector<string> v0;

    // string deQuy(int i, int n) {
    //     for (int j = -1; j <= 1; j += 2) {

    //         if (sum + j >= 0) {
    //             sum += j;
    //             if (i == n) {
                    
    //             }
    //             else {
    //                 deQuy(i + 1, n);
    //                 sum -= j;
    //             }
    //         }
            
    //     }
    //     return;
        
    // }


    void backTrack(vector<string> v, string str, int open, int close, int max) {
        if (str.length() == max * 2) {
            v.push_back(str);
            return;
        }
        if (open < max) {
            backTrack(v, str + "(", open+1, close, max);
        }
        if (close < open) {
            backTrack(v, str + ")", open, close+1, max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        backTrack(v, "", 0, 0, n);
        return v;
    }
};