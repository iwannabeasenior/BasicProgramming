#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a = 0, b = 0;
    // n = 5a - 2b, a + b = min
    for (int i = 0; i < 100000000; i++) {
        if ((n+7*i) % 5 == 0) {
            cout << (n+7*i)/5;
            break;
        }
    }
}