#include<bits/stdc++.h>
using namespace std;
int front, n;
vector<int> v(1000000);
int a[100][1000000];
int compute(int i, int j) {
    if (i == 0) return v[j];
    else {
        if (a[i-1][j] == -100) 
            a[i-1][j] = compute(i-1, j);
        if (a[i-1][j + (int)pow(2, i-1)] == -100) {
            a[i-1][j + (int)pow(2, i-1)] = compute(i-1, j + (int)pow(2, i-1));
        }
        return min(a[i-1][j], a[i-1][j + (int)pow(2, i-1)]);
    }
}
void preprocessing() {
    for (int i = 0; i < front; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -100 && j + (int)pow(2, i) -1 < n) {
                a[i][j] = compute(i, j);
            }
        }
    }
}   
int rmq(int i, int j) {
    int can = (int)log2(j - i + 1);
    if (can * can == j - i + 1) {
        return a[can][i];
    } else {
        return min(a[can][i], a[can][j - (int)pow(2, can) + 1]);
    }
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
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000000; j++) {
            a[i][j] = -100;
        }
    }
    int query; cin >> query;
    int a, b;
    int sum = 0;
    int minValue = 0;
    preprocessing();
    while (query--) {
        cin >> a >> b;
        sum += rmq(a, b);
    }
    cout << sum;
}