#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> stack;
    while (true) {
        string query; cin >> query;
        if (query == "#") break;
        else if (query == "PUSH") {
            int n; cin >> n;
            stack.push(n);
        }
        else {
            if (stack.empty()) {
                cout << "NULL" << endl;
            }
            else {
                int n = stack.top();
                cout << n << endl;
                stack.pop();
            }
        }
    }
}