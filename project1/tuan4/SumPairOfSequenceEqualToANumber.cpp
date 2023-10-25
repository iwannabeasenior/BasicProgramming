#include<bits/stdc++.h>
using namespace std;
int countPair(vector<int> v, int m) {
    
}
int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> map;
    int value;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (map.count(value)) {
            dem++;
        } else {
            map[m-value] = value;
        }
        
    }
    cout << dem;
}