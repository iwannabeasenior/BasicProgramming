#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int sum[1001][1001];
int sum2[1001][1001];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        sum[i][0] = 0;
        sum2[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        sum2[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum2[i][j] = sum2[i-1][j] + sum[i][j];
        }
    }
    sum2[0][0] = 0;
    int k; cin >> k;
    int r1, c1, r2, c2;
    for (int i = 1; i <= k; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        int Sum = 0;
        Sum += sum2[r2][c2] + sum2[r1-1][c1-1] - sum2[r1-1][c2] - sum2[r2][c1-1];
        cout << Sum << endl;
    }
}