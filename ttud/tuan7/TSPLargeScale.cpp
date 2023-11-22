// gready
#include<bits/stdc++.h>
using namespace std;

int a[1000][1000];
bool visited[1000];
int path[1000];
vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> edges(1000);

int main() {
    int n; cin >> n;   
    int value;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> value;
            a[i][j] = value;
            if (i != j) {
                edges[i].push({value, j});
            }
        }
    }
    path[1] = 1;
    int dem = 1;
    int cost = 0;
    int prev = 1;
    visited[1] = true;
    while(dem < n) {
        while (!edges[prev].empty()) {
            auto top = edges[prev].top();
            if (!visited[top.second]) {
                dem++;
                path[dem] = top.second;
                cost += top.first;
                prev = top.second;
                visited[top.second] = true;
                break;
            } else {
                edges[prev].pop();
            }
        }
    }
    cost += a[prev][1];
    cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        cout << path[i] << " ";
    }

    // 2 opt
}
 