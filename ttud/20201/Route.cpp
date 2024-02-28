#include<bits/stdc++.h>
#define N 10001
using namespace std;
int n, Q;
int a[N];
int dis[N][N];
void input() {
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> dis[i][j];
        }
    }
}
void solve() {
// lay hang sao cho Q kien hang, thoi gian lay hang it nhat, den diem i khong nhat thiet phai lay ai kien hang
    
}
int main() {
    input();
}