#include<bits/stdc++.h>
using namespace std;
int n, m;
int record = 0;
int a[10000][10000];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m-1; j >=1; j--) {
            if (a[j][i] != 0) {
                a[j][i] += a[j+1][i];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int max = 0;
        for (int j = 1; j <= n; j++) { 
            if (a[i][j] != 0) {
            int dem = 1;
            int x = j-1;
            int y = j+1;
            while (x >= 1) {
                if (a[i][x] >= a[i][j]) {
                    dem++;
                    x--;
                }
                else break;
            }
            while (y <= n) {
                if (a[i][y] >= a[i][j]){
                    y++;
                    dem++;
                } 
                else break;
            }
            if (dem * a[i][j] > max) max = dem * a[i][j];
            }           
            
        }
        if (max > record) record = max;
    }
    cout << record;
}