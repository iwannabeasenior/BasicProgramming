// tìm tâm điểm của cây
#include<bits/stdc++.h>
#define N 100001
using namespace std;
struct Node {
    int node;
    int weight;
};
int n;
int p[N]; // parent of u
int d[N]; // total distance from u to offspring of u
int num[N]; // total number node in tree- root u
int f[N]; // total distance from all node in tree to u 
vector<Node> A[N];
bool visited1[N] = {false};
bool visited2[N] = {false};

void input() {
    int u, v, w;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        cin >> u >> v >> w;
        A[u].push_back(Node{v, w});
        A[v].push_back(Node{u, w});
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        num[i] = 1;
        f[i] = -1;
    }
}
// compute d[u] and num[u]
void dfs1(int u) {

    visited1[u] = true;
    for (int i = 0; i < A[u].size(); i++) {
        auto v = A[u][i];
        if (!visited1[v.node]) {
            dfs1(v.node);
            d[u] += d[v.node] + v.weight * num[v.node];
            num[u] += num[v.node];
        }
    }
}
// f[root] = d[root], compute f[v] with v is children of u, f[u] is known
void dfs2(int u) {
    visited2[u] = true;

    for (int i = 0; i < A[u].size(); i++) {
        auto v = A[u][i];
        if (!visited2[v.node]) {
            int F = f[u] - (d[v.node] + v.weight * num[v.node]);
            f[v.node] = F + d[v.node] + v.weight * (n - num[v.node]);
            dfs2(v.node);
        }
    }
}

int main() {
    input();
    int root = 1;
    dfs1(root);
    f[root] = d[root];
    dfs2(root);
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] > max) max = f[i];
    }
    cout << max;
}