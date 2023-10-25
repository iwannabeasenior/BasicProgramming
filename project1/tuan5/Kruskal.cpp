#include<bits/stdc++.h>
using namespace std;
class Edge {
    public : 
        int u, v, w;
        Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
};
class dsu {
public : 
    vector<int> parent;
    void init(int n) {
        parent.resize(n+5, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        parent[u] = v;
        return true;
    }
}dsu;
int main() {
    int n, m;
    int u, v, w;
    cin >> n >> m;
    vector<Edge> edge;
    int totalWeight = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge.push_back(Edge(u, v, w));
    }
    sort(edge.begin(), edge.end(), [](Edge& x, Edge& y) {
        return x.w < y.w;
    });
    dsu.init(n);
    for (Edge e : edge) {
        if (!dsu.join(e.u, e.v)) {
            continue;
        }
        totalWeight += e.w;
    }
    cout << totalWeight;
}