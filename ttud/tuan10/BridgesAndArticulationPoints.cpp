
#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
int n, m;
int t = 0;
vector<vector<int>> edges(N);
int low[N], num[N];
bool visited[N] = {false};
int bridges = 0; 
int children = 0; // child of root
int root = 0; // is root
int totalRoot = 0; // total root is articulation point
set<int> articulationPoints;
void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}
void dfs(int s, int ps) {
    if (ps == root) children++;
    t++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;
    for (int i = 0; i < edges[s].size(); i++) {
        int v = edges[s][i];
        if (v == ps) continue; // đã được xét đến rồi, chưa hiểu lắm
        if (visited[v]) {
            // có cạnh ngược từ s -> v
            low[s] = min(low[s], num[v]);
        } else {
            // không có cạnh ngược
            dfs(v, s);
            low[s] = min(low[s], low[v]);
            // if low[v] > num[s] -> bridge
            if (low[v] > num[s]) {
                bridges++;
            }
            if (low[v] >= num[s] && s != root) {
                articulationPoints.insert(s);
            }
        }
    }
}
int main() {
    input();    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            children = 0;
            root = i;
            dfs(i, -1);
            if (children > 1) totalRoot++;
        }
    }
    cout << articulationPoints.size() + totalRoot << " " << bridges;
}