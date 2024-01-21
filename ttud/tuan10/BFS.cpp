#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> edges(10001);
bool visited[10001] = {false};
void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int dinh = q.front();
        cout << dinh << " ";
        q.pop();
        for (auto v : edges[dinh]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return;
}       
int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        sort(edges[a].begin(), edges[a].end());
        sort(edges[b].begin(), edges[b].end());
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) BFS(i);
    }
}