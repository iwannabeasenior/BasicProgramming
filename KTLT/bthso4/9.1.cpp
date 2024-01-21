#include <iostream>
#include <queue>
#include <climits>
#define INF 10000000;
using namespace std;
//Nguyen Trung Thanh - 20215482
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    int n = adj.size();
    bool mark[n] = {false};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> distance (n);
    for (int i = 1; i < n; i++){
        distance[i] = INF;
    }

    distance[0] = 0;
    mark[0] = true;
    
    for (pair<int, int> p : adj[0]){
        distance[p.first] = p.second;
        pq.push(make_pair(distance[p.first],p.first));
    }

    while(!pq.empty()){
        pair<int, int> newP = pq.top();
        pq.pop();
        mark[newP.second] = true;
        for (pair<int, int> p : adj[newP.second]){
            if (!mark[p.first]){
                int z = distance[newP.second] + p.second;
                if (z < distance[p.first]){
                    distance[p.first] = z;
                    // không sợ lặp vì thằng trước nhỏ hơn thằng sau 
                    pq.push(make_pair(distance[p.first],p.first));
                }
            }
        }
    }
    return distance;
    
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}