#include<bits/stdc++.h>
using namespace std;
string pattern, source;
int last(int c, int s, int j) {
    for (int i = j-1; i >= 0; i--) {
        if (pattern[i] == source[s+j]) return i;
    }
    return 0;
}   
void findSubStringLikePattern(string pattern, string source) {
    int n = pattern.length();
    int m = source.length();
    int s = 0;
    while (s <= m - n) { 
        int j = n-1;
        while (j >= 0 && source[s + j] == pattern[j]) {
            j--;
        }
        if (j == -1) {
            cout << "Find pattern in source at "; cout << s << endl;
            s++;
            while (source[s] == pattern[0]){
                s++;
            }
            
        } 
        else {
            int k = last(source[s+j], s, j);
            s = s + max(j-k, 1);
        } 
            
    }
}

int main() {
    cin >> pattern >> source;
    findSubStringLikePattern(pattern, source);
}