#include<bits/stdc++.h>
using namespace std;
int n;
int weight[1000];
vector<vector<int>> edges(1000);

void solve() {
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        vector<vector<int>> subEdges(1000);
        bool visited[1000] = {false};
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                if (!visited[v]) {
                    subEdges[u].push_back(v);
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        // run tree
        int a[1000] = {0};
        
    }

}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    int a, b;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}