#include<iostream>
#include<vector>
#include<queue>
#define INF 100000000
using namespace std;

int n, m;
int D[5001];
int C[5001];
int d[5001] = {-1};
vector<vector<pair<int, int>>> price(10000);
vector<vector<int>> edges(10000);
bool visited[5001] = {false};
int disMin[5001];

int dijkstra(int dinh, int nguon) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // a1 < a2 < a3
    for (auto i : price[dinh]) {
        disMin[i.first] = i.second;
        pq.push({i.second, i.first});
    }
    while (1) {
        pair<int, int> a = pq.top();
        pq.pop();
        visited[a.second] = true;
        if (a.second == nguon) return a.first;
        for (auto i : price[a.second]) {
            if (!visited[i.first] && disMin[i.first] > disMin[a.second] + i.second) {
                disMin[i.first] = disMin[a.second] + i.second;
                pq.push({disMin[i.first], i.first});
            }
        }
    }
}

void BFS(int s) {
    for (int i = 0; i < 5001; i++) {
        d[i] = -1;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int v : edges[front]) {
            if (d[v] == -1 && d[front] < D[s]) {
                q.push(v);
                d[v] = d[front] + 1;
                price[s].push_back({v, C[s]});
            }
        }
    }
}


int main() {
    for (int i = 0; i < 5001; i++) {
        disMin[i] = INF;
    }
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        BFS(i);
    }

    // dijsktra
    cout << dijkstra(1, n);
}