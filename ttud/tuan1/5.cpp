#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<int> queue;
    while (true) {
        string query; cin >> query;
        if (query == "#") break;
        else if (query == "PUSH") {
            int n; cin >> n;
            queue.push(n);
        }
        else {
            if (queue.empty()) {
                cout << "NULL" << endl;
            }
            else {
                int n = queue.front();
                cout << n << endl;
                queue.pop();
            }
        }
    }
}