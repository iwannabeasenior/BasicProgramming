#include<bits/stdc++.h>
using namespace std;
int a[100000];
int sum[100000];

int main() {
    sum[0] = 0;
    int n; cin >> n;
    int value;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] += sum[i-1] + a[i];
    }
    int k;
    cin >> k;
    int x, y;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        cout << sum[y] - sum[x] + a[x] << endl;
    }
}