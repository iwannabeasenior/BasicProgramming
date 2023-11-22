#include<bits/stdc++.h>
#define N 1001
using namespace std;
int n, m, s, t, maxFlow;
int graph[N][N];
int trace[N] = {0};
bool visited[N] = {false};

void dfs(int u, int sink) {
    visited[u] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[u][i] > 0) {
            trace[i] = u;
            dfs(i, sink);
        }
    }
}

bool findWay(int source, int sink) {
    memset(visited, false, sizeof(visited));
    memset(trace, 0, sizeof(trace));
    dfs(source, sink);
    return visited[sink];
}

bool func() { 
    if (findWay(s, t)) {

        // process
        int minCapacity = 10000000;
        int u = t;
        while (u != s) {
            minCapacity = min(minCapacity, graph[trace[u]][u]);
            u = trace[u];
        }
        maxFlow += minCapacity;
        u = t;
        while (u != s) {
            graph[trace[u]][u] -= minCapacity;
            graph[u][trace[u]] += minCapacity;
            u = trace[u];
        }
        return true;
    } 
    return false;
}
int main() {
    cin >> n >> m >> s >> t;
    maxFlow = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    while (func()) {
        
    }
    cout << maxFlow;
}