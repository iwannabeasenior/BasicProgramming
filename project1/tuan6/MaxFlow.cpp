// ford - fulkerson
#include<bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<vector<int>> edges(1000);
int f[1000][1000];
int c[1000][1000];
int trace[1000];
bool visited[1000];

void dfs(int u, int sink) {
    visited[u] = true;
    for (auto v : edges[u]) {
        if (!visited[v]) {
            trace[v] = u;
            dfs(v, sink);
        }
    }
}

bool find_arg_from_to(int source, int sink) {
    memset(trace, 0, sizeof(trace));
    memset(visited, false, sizeof(visited));
    dfs(source, sink);
    return visited[sink];
}

void increaseFlow(int minCapacity, int source, int sink) {
    minCapacity = INFINITY;
    int u = sink;
    int preVertex;
    while (u != source) {
        preVertex = trace[u];
        minCapacity = min(minCapacity, c[preVertex][u] - f[preVertex][u]);
        u = preVertex;
    }

    while(sink != source) {
        preVertex =  trace[sink];
        f[preVertex][sink] += minCapacity; // luong da di qua 
        f[sink][preVertex] -= minCapacity; // luong con lai
        sink = preVertex;
    }
}

int main() {
    cin >> n >> m;
    cin >> s >> t;
    int u, v, w;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            c[i][j] = 0;
            f[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        c[u][v] = w;
        edges[u].push_back(v);
    }

}