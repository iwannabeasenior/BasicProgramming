#include<bits/stdc++.h>
#define N 100001
using namespace std;

void solve() {
    
    int testCase;
    cin >> testCase;
    while (testCase--) {
        // int n; cin >> n;
        // int max = 0;
        // int result = 0;
        // stack<int> s;
        // for (int i = 0; i < n; i++) {
        //     int value; cin >> value;
        //     if (s.empty()) {
        //         s.push(value);
        //     } else {
        //         int top = s.top();
        //         if (value - top == 1) {
        //             s.push(value);
        //         } else {
        //             result = s.size();
        //             if (result > max) max = result;
        //             while (!s.empty()) {
        //                 s.pop();
        //             }
        //             s.push(value);
        //         }
        //     }
        // }
        // cout << max << endl;
        int n; cin >> n;
        int res = 0;
        map<long long, vector<int>> pos;
        int A[N];
        int S[N];
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (pos.count(A[i])) {
                pos[A[i]].push_back(i);
            } else {
                vector<int> a;
                a.push_back(i);
                pos.insert(make_pair(A[i], a));
            }
        }
        S[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = 0; k < pos[A[i]-1].size(); k++) {
                int v = pos[A[i]-1][k];
                if (v >= i) continue;
                else {
                    if (S[v] + 1 > S[i]) S[i] = S[v] + 1;
                    res = max(res, S[i]);
                }
            }
        }
        cout << res << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}