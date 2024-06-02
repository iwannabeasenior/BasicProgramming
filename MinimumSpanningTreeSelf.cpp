#include<bits/stdc++.h>
// giai bai 2
using namespace std;
int minDistance = 0;
int n;
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
};
vector<Edge> edges;
class DSU {
public:
    vector<int> parent;
    void init() {
        parent.resize(n+2);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else {
            return parent[u] = findParent(parent[u]);
        }
    }
    bool join(int u, int v) {
        if (parent[u] == parent[v]) return false;
        else {
            u = parent[u];
            v = parent[v];
            parent[u] = v;
            return true;
        }
    }
};
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), [] (Edge& a, Edge& b) {
        return b.w - a.w;
    });
}
int main() {
    input();
    DSU dsu;
    dsu.init();
    int count = 0;
    for(auto edge : edges) {
        if (!(dsu.join(edge.u, edge.v))) {
            continue;
        } else {
            count++;
            minDistance += edge.w;
            if (count == n-1) break;
        }
    }
}