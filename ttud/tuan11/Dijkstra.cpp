#include<bits/stdc++.h>
#define INF 10000000;
using namespace std;
int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> edges(1000001); 
bool visited[100001] = {false};
int disMin[100001];
int dijkstra(int dinh, int nguon) {
    
    for (auto i : edges[dinh]) {
        disMin[i.first] = i.second;
        pq.push({i.second, i.first});
    }
    while (1) {
        pair<int, int> a = pq.top();
        pq.pop();
        visited[a.second] = true;
        if (a.second == nguon) return a.first;
        for (auto i : edges[a.second]) {
            if (!visited[i.first] && disMin[i.first] > disMin[a.second] + i.second) {
                disMin[i.first] = disMin[a.second] + i.second;
                pq.push({disMin[i.first], i.first});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < 100001; i++) {
        disMin[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }    
    int u, v;
    cin >> u >> v;
    cout << dijkstra(u, v);
}   