#include<bits/stdc++.h>
using namespace std;
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (int num : nums) {
            v.push_back(to_string(num));
        }
        sort(v.begin(), v.end(), [] (string a, string b) {
            return a + b > b + a;
        });
        string ans = "";
        for (string str : v) {
            ans += str;
        }
        if (ans[0] == '0') return "0";
        return ans;
    }
};
// c2 : priority queue,  913, 9, 98 -> đưa về 9,13913, 9,99999, 9,89898
class Solution {
public:
    string largestNumber(vector<int>& nums) {

    }
};
int main() {

}
