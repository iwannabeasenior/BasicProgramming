#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        int len = s.length();
        int tong = m[s[len-1]];
        for (int i=len-2; i>=0; i--){
            if (m[s[i]] < m[s[i+1]]){
                tong -= m[s[i]];
            }
            else tong += m[s[i]];
        }
        return tong;
    }
};
int main(){

}