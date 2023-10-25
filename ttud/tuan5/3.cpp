#include<bits/stdc++.h>
using namespace std;
int v1[10001];
int v2[10001];
int a[10001][10001];
int main() {
    int n, m; cin >> n >> m;
    
    int maxValue = -100000;
    
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
        a[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> v2[i];
        a[0][i] = 0;
    }
    a[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
                if (v1[i] == v2[j]) {
                    a[i][j] =  a[i-1][j-1] + 1;
                } else {
                    a[i][j] = max(a[i][j-1], a[i-1][j]);
                }
                if (maxValue < a[i][j]) maxValue = a[i][j];
        }
    }
    cout << maxValue;
}