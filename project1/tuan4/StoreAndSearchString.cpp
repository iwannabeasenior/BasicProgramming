#include<bits/stdc++.h>
using namespace std;
int main() {
    string text;
    unordered_set<string> s;
    while (cin >> text) {
        if (text != "*") {
            s.insert(text);
        } else {
            break;
        }
    }
    string query;
    string value;
    while (cin >> query) {
        if (query != "***") {
            if (query == "insert") {
                cin >> value;
                if (s.find(value) == s.end()) {
                    s.insert(value);
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            } else {
                cin >> value;
                if (s.find(value) != s.end()) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        } else {
            break;
        }
    }
}