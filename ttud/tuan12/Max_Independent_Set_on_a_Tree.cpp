// n vertexs, n-1 edges => đồ thị không có chu trình, cây dfs không bao giờ có cạnh ngược
// cũng đủ n-1 cạnh, chỉ là sắp xếp lại đồ thị 
#include<bits/stdc++.h>
using namespace std;
#define N 100001
int n;
vector<int> A[N];
vector<int> C[N];
int W[N];
int p[N];
bool visited[N];
int root;
int d[N];
int F1[N];
int F0[N];
int F[N];
int ans;
int cF(int u);
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];

        F1[i] = -1;
        F0[i] = -1;
        F[i] = -1;
        d[i] = 0;
        visited[i] = false;
    }

    int a, b;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < A[u].size(); i++) {
        int v = A[u][i];
        if (!visited[v]) {
            p[v] = u; d[u] += 1; C[u].push_back(v);
            dfs(v);
        }
    }
}

int cF0(int u) {
    if (F0[u] >= 0) return F0[u];
    F0[u] = 0;
    for (int i = 0; i < C[u].size(); i++) {
        int v = C[u][i];
        F0[u] += cF(v);
    }
    return F0[u];
}

int cF1(int u) {
    if (F1[u] >= 0) return F1[u];
    F1[u] = W[u];
    for (int i = 0; i < C[u].size(); i++) {
        int v = C[u][i];
        F1[u] += cF0(v);
    }
    return F1[u];
}

int cF(int u) {
    if (F[u] >= 0) return F[u];
    F[u] = max(cF0(u), cF1(u));
    return F[u];
}

int main() {
    input();
    root = 1;
    dfs(root);
    cout << cF(root);
}