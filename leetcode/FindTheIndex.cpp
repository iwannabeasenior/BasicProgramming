// two pointer
#include <bits/stdc++.h>
using namespace std;
// c1 : use find function
class Solution {
public:
    int strStr(string haystack, string needle) {
        // needle in haystack
        if (haystack.find(needle) != string::npos) {
            return haystack.find(needle);
            
        }
        return -1;
    }
};
// c2 : use two pointer
class Solution {
public: 
    int strStr(string haystack, string needle) {
        int lenOfHaystack = haystack.length();
        int lenOfNeedle = needle.length();
        int len = lenOfHaystack - lenOfNeedle;
        for (int i = 0; i <= len; i++) {
            string subStr = haystack.substr(i, lenOfNeedle);
            if (subStr == needle) return i;
        }
        return -1;
    }
};