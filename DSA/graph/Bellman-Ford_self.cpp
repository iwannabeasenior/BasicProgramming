#include<bits/stdc++.h>
#define INF 1000000 
using namespace std;
int n, u, v, w, dinh;
int dem = 0;
vector<pair<int, int>> BellmanFord(const vector<vector<pair<int, int>>> &adj, int u){
    vector<pair<int, int>> v(dinh);
    for (int i = 0; i < dinh; i++){
         v[i] = {100, -1};
    }
    
    v[u] = {0, u};
    int count = 1;
    while (count){
        count = 0;
        for (int i = 0; i < dinh; i++){
            // p {a,b}, a : dinh cuoi, b : trong so
            for (pair<int, int> p : adj[i]){

                int u = p.second + v[i].first;
                if (u < v[p.first].first){
                    v[p.first].first = u;
                    v[p.first].second = i;
                    count++;
                } 
            
            }

        }
    }
    return v;
}


int main(){
    cin >> n >> dinh;

    vector<vector<pair<int, int>>> adj(dinh);

    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    };

    for (int i = 0; i < n; i++){
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    int dinh_xuat_phat;
    cin >> dinh_xuat_phat;
    
    vector<pair<int, int>> v = BellmanFord(adj, dinh_xuat_phat);
    for (pair<int, int> p : v){
        cout << p.first << "\n";
    }

}