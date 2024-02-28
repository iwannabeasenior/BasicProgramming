#include<bits/stdc++.h>
using namespace std;
int n; 
bool visited[1000] = {false};
int cost = 0;
int record = 10000000000;
int minCost = 10000000000;
int a[1000][1000];
int trace[1000];
void travel(int t) {
    for (int i = 1; i <= n; i++) {
        
        if (!visited[i]) {
            trace[t] = i;
            visited[i] = true;
            cost += a[trace[t-1]][i];
            if (t == n) {
                if (cost + a[i][1] < record) record = cost + a[i][1];
            } else {
                if (cost + minCost * (n - t + 1) < record)
                travel(t+1);
            }
            cost -= a[trace[t-1]][i];
            visited[i] = false;
        }
    }
}
int main() {
    for (int i =0; i < 1000; i++) {
        visited[i] = false;
    }
    cin >> n;
    int k;
    trace[1] = 1;
    visited[1] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> k;
            a[i][j] = k;
            if (k < minCost) minCost = k;
        }
    }
    travel(2);
    cout << record;
}
