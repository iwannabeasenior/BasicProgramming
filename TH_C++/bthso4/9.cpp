#include <iostream>
#include <queue>
#include <climits>
#define INF 10000000;
using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    int n = adj.size();
    bool mark[n] = {false};
    vector<int> distance (n);
    distance[0] = 0;

    mark[0] = true;

    for (int i = 1; i < n; i++){
        distance[i] = INF;
    }
    
    for (pair<int, int> p : adj[0]){
        distance[p.first] = p.second;
    }
    int min = INF + 1;
    int add = INF + 1;
    bool flag = false;
    while(!flag){
        for (int i = 1; i < n; i++ ){
            if (!mark[i]){
                if (distance[i] < min){
                    min = distance[i];
                    add = i;
                }
            }
        }
        mark[add] = true;
        for (pair<int, int> p : adj[add]){
            if (!mark[p.first]){
                int z = distance[add] + p.second;
                if (z < distance[p.first]){
                    distance[p.first] = z;
                }
            }
        }
        min = INF + 1;
        add = INF + 1;
        for (int i = 0; i < n; i++){
            if (!mark[i]){
                flag = false;
                goto J;
            }
        }
        flag = true;
        J : 1;
    }
    return distance;
    
}

int main() {
    freopen("C:\\Users\\NguyenTrungThanh\\Downloads\\input.txt", "r+", stdin);

    int n, m; cin >> n >> m;
    vector< vector< pair<int, int> > > adj(n+1);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    // add_edge(0, 1, 4);
    // add_edge(0, 7, 8);
    // add_edge(1, 7, 11);
    // add_edge(1, 2, 8);
    // add_edge(2, 3, 7);
    // add_edge(2, 8, 2);
    // add_edge(3, 4, 9);
    // add_edge(3, 5, 14);
    // add_edge(4, 5, 10);
    // add_edge(5, 6, 2);
    // add_edge(6, 7, 1);
    // add_edge(6, 8, 6);
    // add_edge(7, 8, 7);
    int u, v, w;
    adj[0].emplace_back(1, 0);
    adj[1].emplace_back(0, 0);
    for (int i = 0; i < m ; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> distance = dijkstra(adj);
    // for (int i = 0; i < distance.size(); ++i) {
    //     cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    // }
    cout << "abc" << endl;
    return 0;
}