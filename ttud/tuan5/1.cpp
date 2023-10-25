#include<bits/stdc++.h>
using namespace std;
int front, n;
vector<int> v(1000000);
int a[25][1000000];
int compute(int i, int j) {
    if (i == 0) return v[j];
    else {
        if (a[i-1][j] == -1) 
            a[i-1][j] = compute(i-1, j);
        if (a[i-1][j + (1 << i-1)] == -1) {
            a[i-1][j + (1 << i-1)] = compute(i-1, j + (1 << i-1));
        }
        return min(a[i-1][j], a[i-1][j + (1 << i-1)]);
    }
}
void preprocessing() {
    for (int i = 0; i < front; i++) {
        for (int j = 0; j + (1 << i) -1 < n; j++) {
            if (a[i][j] == -1) {
                a[i][j] = compute(i, j);
            }
        }
    }
}   
int rmq(int i, int j) {
    int k = 0;
    while ((1 << k+1 <= j - i + 1)) {
        k++;
    }
    return min(a[k][i], a[k][j - (1 << k) + 1]);
}
// a[front][n];
// a[x][y] : y -> y + 2^x - 1;
// 3-6 : a[2][3] min (a[1][3] , a[1][3 + 2^x-1])
// a[0][y] -> phan tu nho nhat la y
int main() {
    cin >> n;
    front = log2(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 1000000; j++) {
            a[i][j] = -1;
        }
    }
    int query; cin >> query;
    int a, b;
    int sum = 0;
    preprocessing();
    while (query--) {
        cin >> a >> b;
        sum += rmq(a, b);
    }
    cout << sum;
}