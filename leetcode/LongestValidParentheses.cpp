#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        // tach chuoi thanh mang ki tu
        char* char_array = new char[len+1];
        strcpy(char_array, s.c_str());

        stack<pair<char, int>> sc;
        int max = 0;
        int dem = 0;
        for (int i=0; i<len; i++){
            if (char_array[i] == '('){
                sc.push(make_pair('(', i));    
            }   
            else {
                if (!sc.empty() && sc.top().first == '('){
                    sc.pop();
                }
                else {
                    sc.push({')', i});
                }
            }
        }
        if (sc.empty()) return len;
        
        int right = len-1;
        int left;

        if (right - sc.top().second  > max ) max = right - sc.top().second;

        while (!sc.empty()){
            if (sc.size() == 1){
                if (sc.top().second > max) max = sc.top().second;
                return max;
            } 
            right = sc.top().second;
            sc.pop();
            left = sc.top().second;
            if (right - left -1 > max) max = right - left -1;
        }
        return max;
    }
};

int main(){
    string s;
    cin >> s;
    Solution t;
    cout << t.longestValidParentheses(s);
}