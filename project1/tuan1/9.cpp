#include<bits/stdc++.h>
using namespace std;
bool checkFormat(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (i == 2 || i == 5) {
            if (s[i] != ':') return false;
        }else {
            if (!isdigit(s[i])) return false;
        }
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    if (checkFormat(s)) {
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3, 2));
        int second = stoi(s.substr(6, 2));
        if (0 <= hour && hour <=23 && minute >= 0 && minute <=59 && second >= 0 && second <=59) {
             cout << (second + minute*60 + hour*60*60); 
        } else {
            cout << "INCORRECT";
        }
    } else {   
        cout << "INCORRECT";
    }
    
}