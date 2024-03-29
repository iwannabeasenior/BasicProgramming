// floyd-warshall
#include<bits/stdc++.h>
using namespace std;
int n, m, u, v, w;
int a[10000][10000];

int main() {
    cin >> n >> m;
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 1e5;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        a[u][v] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][k] != 1e5 && a[k][j] != 1e5 && i != j) {
                    if (a[i][j] > a[i][k] + a[k][j]) {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n" [j == n];
        }
    }
}