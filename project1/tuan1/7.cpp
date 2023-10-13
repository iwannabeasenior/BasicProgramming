#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> v(n);
    int countOdd = 0;
    for (int i : v) {
        cin >> i;
        if (i % 2) countOdd++;
    }
    cout << countOdd << " " << n - countOdd;
}