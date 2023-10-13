#include<bits/stdc++.h>
using namespace std;
int main() {
    
    set<string> DB;
    string s;
    while(true) {
        cin >> s;
        if (s == "*") {
            break;
        }
        else DB.insert(s);
    }
    while (true) {
        string query; cin >> query;
        if (query == "***") break;
        else if (query == "find") {
            string k;
            cin >> k;
            if (DB.find(k) != DB.end()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }else if (query == "insert") {
            string k;
            cin >> k;
            if (DB.find(k) != DB.end()) {
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
                DB.insert(k);
            }
        }
    }
}