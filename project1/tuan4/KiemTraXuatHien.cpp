#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (s.find(v[i]) != s.end()) {
            cout << 1 <<  " ";
        } else {
            cout << 0 << " ";
            s.insert(v[i]);
        }
    }
}