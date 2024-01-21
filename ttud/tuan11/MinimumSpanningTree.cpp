#include<bits/stdc++.h>
using namespace std;
int n, m;

int minDistance = 0;
struct Edge {
  int u, v, w;
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
};
vector<Edge> edges;
class dsu {
public: 
    vector<int> parent;
    void init(int n) {
        parent.resize(n+2);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    int join(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        if (u == v) {
            return false;
        }
        parent[v] = u;
        return true;
    }

};

int main() {
    
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return b.w - a.w; // if (a.w < b.w => return 1 (a before b))
    });
    dsu dsu;
    dsu.init(n);
    int dem = 0;
    for (Edge e : edges) {
        if (!dsu.join(e.u, e.v)) {
            continue;
        }
        dem++;
        minDistance += e.w;
        if (dem == n-1) {
            break;
        }
    }
    cout << minDistance;
}