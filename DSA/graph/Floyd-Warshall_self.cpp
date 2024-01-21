#include<bits/stdc++.h>
#define INF 100
using namespace std;
int u, v, w, n, q;
int a[1000][1000];

void FloydWarshall(){
    
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = INF;
        }
    }
    vector<vector<pair<int, int>>> adj(100);
    cin >> q;
    // auto edge = [&adj] (int u, int v, int w){
    //     adj[u].push_back({v,w});
    // };

    // for (int i = 0; i < q; i++){
    //     cin >> u >> v >> w;
    //     edge(u, v, w);
    // }
    // khoi tao gia tri ban dau
    
    for (int i = 0; i < q; i++)
    {
        cin >> u >> v >> w;
        a[u][v] = w;
    }
    
    for (int i = 1; i <=n; i++){
        a[i][i] = 0;
    }
    
    // for (int i = 1; i <= n; i++){
    //     for (pair<int, int> p : adj[i]){
    //         a[i][p.first] = p.second;
    //     }
    // }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j] && a[i][k] != INF && a[k][j] != INF && a[i][j] != 0){
                    a[i][j] = a[i][k] + a[k][j];
                   
                }
            }
        }
    }
    FloydWarshall();  

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j] << " \n" [j==n];
        }
    }

}