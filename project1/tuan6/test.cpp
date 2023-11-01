#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(pair<int,int>(1,2));
    pq.push({3,5});
    pq.push({0,4});
    while (!pq.empty()) {
        auto top = pq.top();
        cout << top.first;
        pq.pop();
    }
}