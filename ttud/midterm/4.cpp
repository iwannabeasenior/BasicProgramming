#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1000][1000];
bool visited[1000];
int b[1000];
int dem = 0;
int minLen = 1000;
int currentPrice = 0;
void Try(int k) {
    for (int i = 1; i <= n; i++) {
       if (!visited[i]) {
            visited[i] = true;
            b[k] = i;
            currentPrice += a[b[k-1]][i]; 
            if (k == n) {
                if (currentPrice + a[i][1] <= m) dem++;
            } else {
                if (currentPrice + (n - k + 1) * minLen < m) {
                    Try(k+1);
                }
            }
            b[k] = 0;
            currentPrice -= a[b[k-1]][i];
            visited[i] = false;
       } 
    }
    
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] < minLen) minLen = a[i][j];
        }
    }
    visited[1] = true;
    b[1] = 1;
    Try(2);
    cout << dem;
}