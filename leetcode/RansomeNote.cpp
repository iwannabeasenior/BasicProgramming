#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26];
        for (char ch : ransomNote) {
            count[ch - 'a']++;
        }
        for (char ch : magazine) {
            count[ch - 'a']--;
            if (count[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
int main() {
    
}