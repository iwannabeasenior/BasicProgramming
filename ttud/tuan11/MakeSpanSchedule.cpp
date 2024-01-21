#include<bits/stdc++.h>
using namespace std;
int n, m;
int d[10001];
int D[10001] = {0};
int S[10001] = {0};
vector<int> topo;
vector<vector<int>> edges(10001);
void topoSort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (D[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        topo.push_back(top);
        for (int i : edges[top]) {
            D[i]--;
            if (D[i] == 0) {
                q.push(i);
            }
        }
    }
}
int makeSpanSchedule() {
    for (int v = 1; v <= n; v++) S[v] = 0;
    int res = 0;
    for (int i = 0; i < topo.size(); i++) {
        int u = topo[i];
        res = max(res, S[u] + d[u]);
        for (int j = 0; j < edges[u].size(); j++) {
            S[edges[u][j]] = max(S[edges[u][j]], S[u] + d[u]);
            res = max (res, S[edges[u][j]]);
        }
    }
    return res;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        D[b]++;
    }
    topoSort(n);
    cout << makeSpanSchedule();
}