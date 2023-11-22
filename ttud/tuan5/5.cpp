//  Longest Increasing subsequence
#include<bits/stdc++.h>
using namespace std;
int a[10000];
int S[10000];
int countMax = 0;
int main() {
    int n; cin >> n;
    for (int i = 0; i < 10000; i++) {
        S[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    S[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (S[j] + 1 > S[i]) S[i] = S[j] + 1;
            } 
        }
        if (S[i] > countMax) countMax = S[i];
    }
    cout << countMax;
}