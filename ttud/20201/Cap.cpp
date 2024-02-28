#include<bits/stdc++.h>
#define N 100001
using namespace std;
int testCase;
void solve() {
    cin >> testCase;
    while(testCase--) {
        int count = 0; // result 
        int n, m; cin >> n;
        vector<int> arrayN;
        for (int i = 0; i <= n-1; i++) {
            int value;
            cin >> value;
            arrayN.push_back(value);
        }
        cin >> m;
        vector<int> arrayM;
        for (int i = 0; i <= m-1; i++) {
            int value; cin >> value;
            arrayM.push_back(value);
        }
        sort(arrayN.begin(), arrayN.end());
        sort(arrayM.begin(), arrayM.end());
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (arrayN[i] == arrayM[j]) {
                count++;
                i++; j++;
            } else if (arrayN[i] < arrayM[j]) {
                i++;
            } else {
                j++;
            }
        }
        cout << count;
        // solve
        
    }
}
int main() {
    solve();
}