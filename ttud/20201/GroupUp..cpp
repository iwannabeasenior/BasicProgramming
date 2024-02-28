#include<bits/stdc++.h>
using namespace std;

int groupUp(int n, vector<int> a) {
    if (a.size() == 1) return 0;
    int maxTime = 0;
    vector<int> b;
    if (n % 2 == 0) {
        for (int i = 0; i < n-1; i+=2) {
            int res = a[i] + a[i+1];
            if (res > maxTime) maxTime = res;
            b.push_back(res);
        }
    } else {
        for (int i = 0; i < n-2; i+=2) {
            int res = a[i] + a[i+1];
            if (res > maxTime) maxTime = res;
            b.push_back(res);
        }
        b.push_back(a[n-1]);
    }
    return maxTime + groupUp(b.size(), b);
}
void solve() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        int n; cin >> n;
        vector<int>a;
        for (int i = 0; i < n; i++) {
            int value; cin >> value;
            a.push_back(value);   
        }
        cout << groupUp(n, a) << endl;
    }
}

int main() {
    solve();   
}