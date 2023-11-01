#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int n, m;
vector<vector<pair<int, int>>> edges(100001);

priority_queue<p, vector<p>, greater<p>> pq;
bool visited[100001];
int minDis[100001];
// dijsktra
int dijkstra(int s, int t) {
    for (int i = 0; i < 100001; i++) {
        minDis[i] = 1e5;
    }
    for (auto edge : edges[s]) {
        pq.push({edge.second, edge.first});
        minDis[edge.first] = edge.second;
    }
    while(1) {
        auto top = pq.top();
        if (top.second == t) return top.first;
        pq.pop();
        visited[top.second] = true;
        for (auto edge : edges[top.second]) {
            if (!visited[edge.first] && edge.second + minDis[top.second] < minDis[edge.first]) {
                minDis[edge.first] = edge.second + minDis[top.second];
                pq.push({minDis[edge.first], edge.first});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    int s, t;
    cin >> s >> t;
    cout << dijkstra(s, t);
}