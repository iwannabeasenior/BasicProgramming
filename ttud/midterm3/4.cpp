#include<bits/stdc++.h>
using namespace std;
int n, K, Q;
int d[1000];
int c[1000][1000];
int M;

int main() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0;  j <= n; j++) {
            cin >> c[i][j];
        }
    }
    cin >> M;
    int a, b;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
    }
}