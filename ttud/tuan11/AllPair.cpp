//C++ 
#include <bits/stdc++.h> 
#define INF 1000000
using namespace std;
int a[10001][10001];
int main() 
{ 
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            a[i][j] = INF;
        }
    }
    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        a[x][y] = z;
    }
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][k] != INF && a[k][j] != INF && a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
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