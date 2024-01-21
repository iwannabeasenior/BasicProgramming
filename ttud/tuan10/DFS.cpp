#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> edges(1000);
bool visited[1000] = {false};
void DFS(int u) {
    visited[u] = true;
    cout << u << " ";
    for (auto v : edges[u]) {
        if (!visited[v]) {
            DFS(v);
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
    }
    DFS(1);
    
}