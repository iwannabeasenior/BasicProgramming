#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    string query;
    int number;
    while (cin >> query) {
        if (query == "PUSH") {
            cin >> number;
            q.push(number);
        } else if (query == "POP") {
            if (!q.empty()) {
                int numberPop = q.front();
                q.pop();
                cout << numberPop << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else {
            break;
        }
    }
}