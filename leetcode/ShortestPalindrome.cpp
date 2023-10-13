#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define d 10

int rabinKarp(char pattern[], char text[], int q) {
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m){
        cout << "Pattern is found at position: " << i + 1 << endl;
        return i;
      }
        
    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
  return -1;
}

class Solution {
public:
    string shortestPalindrome(string s) {
        string s1 = s;
        int len = s.length();
        reverse(s1.begin(), s1.end());
        const int length = s.length();
    
        // declaring character array (+1 for null terminator)
        char* char_array = new char[length + 1];
    
        // copying the contents of the
        // string to char array
        strcpy(char_array, s.c_str());

        for (int i = 0; i < s.length(); i++)
        {
            
      
        string s2 = s1.substr(i, len-i);
        int len2 = s2.length();
        // declaring character array (+1 for null terminator)
        char* char_array2 = new char[len + 1];
    
        // copying the contents of the
        // string to char array
        strcpy(char_array2, s2.c_str());
            int t = rabinKarp(char_array, char_array2, 13);
            if (t != -1){
                string newString =   
            }
        }
        
    }
};

int main(){
    Solution s;
    s.shortestPalindrome("abc");
}

