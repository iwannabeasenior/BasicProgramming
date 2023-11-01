#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> seg;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
int main() {
    int n; cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        seg.push_back({a, b});
    }
    sort(seg.begin(), seg.end(), comp);
   
    int len = 1;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        if (seg[i].first > seg[prev].second) {
            prev = i;
            len ++;
        }
    }
    cout << len;
}