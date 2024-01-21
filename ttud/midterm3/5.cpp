#include<bits/stdc++.h>
using namespace std;
int n, m;
int Q[10000][10000];
int d[10000][10000];
int q[10000];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            cin >> d[i][j]; 
        }
    }    
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    
}