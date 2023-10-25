#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> edges[1000];
bool visited[1000];
queue<int> q;
void init() {
    memset(visited, false, sizeof(visited));
}
void BFS(int k) {
    q.push(k);
    visited[k] = true;
    while (!q.empty()) {
        int front = q.front();
        cout << front << " ";
        q.pop();  
        for (int i : edges[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
}
int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        sort(edges[a].begin(), edges[a].end());
        sort(edges[b].begin(), edges[b].end());
    }
    init();
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) BFS(i);
    }
}