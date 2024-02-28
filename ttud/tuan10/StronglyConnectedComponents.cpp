#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> edges(10000);
bool visited[10000] = {false};

void input() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
    }
}
bool dfs(int crr, int des, vector<int>& visited) {
    if (crr == des) return true;
    visited[crr] = 1;
    for(auto c : edges[crr]) {
        if (!visited[c]) {
            if(dfs(c, des, visited)) {
                return true;
            }
        } 
    }
    return false;
}

bool isPath(int src, int des) {
    vector<int> visited(n+1, 0);
    if (dfs(src, des, visited)) {
        return true;
    } 
    return false;
}

// find number of CSS in directed graph, a->i->b, b->i->a, => all vertices go to other vertices through i, each i coressponds to a CSS 
int findCountCSS() {
    int count = 0;
    vector<int> is_scc(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!is_scc[i]) {
            count++;
            for (int j = i+1; j <= n; j++) {
                if (!is_scc[j] && isPath(i, j) && isPath(j, i)) {
                    is_scc[j] = 1;
                }
            }
        }
    }
    return count;
}

int main() {
    input();
    cout << findCountCSS();
}

// cach 2: su dung low and num
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, m;
vector<int> A[N];
int low[N], num[N];
stack<int> scc;
bool inStack[N] = {false};
int nbscc = 0;
int t = 0;
void input() {
    cin >> n >> m;
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        num[k] = -1;
        inStack[k] = false;
    }
}
void dfs(int u, int pu) {

    t++; num[u] = t; scc.push(u); inStack[u] = true;

    for (int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if (num[v] > 0) {
            if (inStack[v]) low[u] = min(low[u], num[v]);
        } else {
            dfs(v, u); low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]) {
        while (true) {
            int x = scc.top();
            inStack[x] = false;
            scc.pop();
            if (x == u) break;
        }
        nbscc++;
    }
}
int main() {
    input();
    for (int i = 1; i <= n; i++) {
        if (num[i] == -1) {
            dfs(i, -1);
        }
    }
    cout << nbscc;
}