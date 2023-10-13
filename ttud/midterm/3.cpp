#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> pq;
    string query;
    int value;
    while (cin >> query) {
        if (query == "PUSH") {
            cin >> value;
            pq.push(value);
        } else if (query == "POP") {
            cout << pq.top() << " ";
            pq.pop();

        } else {
            break;
        }
    }
   
}