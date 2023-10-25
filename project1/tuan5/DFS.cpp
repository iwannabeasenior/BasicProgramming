#include<bits/stdc++.h>
using namespace std;
int n, m; 
vector<int> edges[1000];
bool visited[1000];
void init() {
    memset(visited, false, sizeof(visited));
}
queue<int> q;
void DFS(int k) {
    if (!visited[k]) {
        visited[k] = true;
        q.push(k);
        for (int i : edges[k]) {
            DFS(i);
        }
    }
}
int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0 ; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    DFS(1);
    while (!q.empty()) {
        int a = q.front();
        cout << a << " ";
        q.pop();
    }
}