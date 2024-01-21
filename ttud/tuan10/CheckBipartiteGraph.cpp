#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> parent;
vector<vector<int>> edges(200001);
bool visited[200001] = {false};
bool isBipartiteGraph(int u) {
    parent[u] = -1;
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int dinh = q.front();
        q.pop();
        if (parent[dinh] == -1) {
            for (auto v : edges[dinh]) {
                if (!visited[v]) {
                    parent[v] = -2;
                    visited[v] = true;
                    q.push(v);
                } else {
                    if (parent[v] == -1) {
                        return false;
                    }
                }
            }  
        } else {
            for (auto v : edges[dinh]) {
                if (!visited[v]) {
                    parent[v] = -1;
                    visited[v] = true;
                    q.push(v);
                } else {
                    if (parent[v] == -2) {
                        return false;
                    }
                }
            }  
        }
        
    }
    return true;
    
}
int main() {
    cin >> n >> m;  
    int a, b;
    parent.resize(n+5, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    // -1 is A, -2 is B
    parent[1] = -1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)  {
        if (!visited[i]) {
            if (isBipartiteGraph(i)) {

            }else {
                cout << 0; 
                return 0;
            }
        } 
    }
    cout << 1;

}