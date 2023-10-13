#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> sc;
        // tach chuoi thanh mang ki tu
        char* char_array = new char[len+1];
        strcpy(char_array, s.c_str());

        for (int i=0; i<len; i++){
            if (char_array[i] == '{' || char_array[i] == '[' || char_array[i] == '('){
                sc.push(char_array[i]);
                continue;
            }
            
            if (char_array[i] == ')'){
                if (sc.empty()) return false;
                char c = sc.top();
                if (c == '(') sc.pop();
                else return false;
            }
            else if (char_array[i] == ']'){
                if (sc.empty()) return false;
                char c = sc.top();
                if (c == '[') sc.pop();
                else return false;
            } 
            else {
                if (sc.empty()) return false;
                char c = sc.top();
                if (c == '{') sc.pop();
                else return false;
            }  
        }
        if (sc.empty()) return true;
        else return false;
    }
};

int main(){

}