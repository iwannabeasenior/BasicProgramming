#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> edges(10000);
bool visited[10000] = {false};
int main() {
    int count = 0;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
    }
    stack<int> st;
    
}