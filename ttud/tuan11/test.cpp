#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> pq;
    pq.push(1);
    pq.push(0);
    pq.push(5);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}