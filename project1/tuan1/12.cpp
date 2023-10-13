#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += v[i];
    } 
    int count = 0;
    if (sum % 2 == 0) count++;
    for (int i = k; i < n; i++) {
        sum = sum + v[i] - v[i-k];
        if (sum % 2 == 0) count++;
    }
    cout << count;
}