#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> edges(100001); 
int BFS1(int s) {
    int price[100001] = {0};
    bool visited[100001] = {false};
    visited[s] = true;
    queue<int> q;
    q.push(s);
    int max = 0;
    int result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto p : edges[u]) {
            if (!visited[p.first]) {
                price[p.first] = price[u] + p.second;
                if (price[p.first] > max) {
                    max = price[p.first];
                    result = p.first;
                }
                q.push(p.first);
                visited[p.first] = true;
            }
        }
    }
    
    return result;
}
int BFS2(int s) {
    int price[100001] = {0};
    bool visited[100001] = {false};
    visited[s] = true;
    queue<int> q;
    q.push(s);
    int max = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto p : edges[u]) {
            if (!visited[p.first]) {
                price[p.first] = price[u] + p.second;
                if (price[p.first] > max) max = price[p.first];
                q.push(p.first);
                visited[p.first] = true;
            }
        }
    }
    
    return max;
}
int main() {
    int n;
    cin >> n;
    int u, v, w;
    string str;
    while (1) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    int s = BFS1(1);
    cout << BFS2(s);
}