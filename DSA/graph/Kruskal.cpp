#include<bits/stdc++.h>
using namespace std;


struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {};
};
typedef struct Edge Edge;

// disjoint set union
struct dsu{
    vector<int> par;
    void init(int n){
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]); 
    }

    bool join(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;
int n, m, totalWeight = 0;
vector<Edge> edge;

int main(){    

    cin >> n >> m;
    int u, v, w;

    for (int i = 1; i <= m; i++){
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    dsu.init(n);

    sort(edge.begin(), edge.end(), [](Edge &x, Edge &y){
        return x.w < y.w;
    });

    for (Edge e : edge){
        
        if (!dsu.join(e.u, e.v)) continue;

        totalWeight += e.w;
    }
    cout << totalWeight;
}