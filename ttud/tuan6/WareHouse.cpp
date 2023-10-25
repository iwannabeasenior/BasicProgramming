// down-top : không đệ quy
// top -down : đệ quy có nhớ
#include<bits/stdc++.h>

using namespace std;
int N, T, D;
int S[1000][1000];
int a[1000];
int t[1000];
void init() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            S[i][j] = -1;
        }
        memset(a, -1, sizeof(a));
        memset(t, -1, sizeof(t));
    }
}
int cal(int i, int k) {
    
    if (S[i][k] != -1) return S[i][k];
    else if (i == 1) {
        if (k == t[1]) return S[i][k] = a[1];
        else S[i][k] = 0;
        return S[i][k];
    } else {
        int maxValue = 0;
        for (int j = max(i-D, 1); j < i; j++) {
            if (k-t[i] >= t[j] && S[j][k-t[i]] == -1) S[j][k-t[i]] = cal(j, k-t[i]);
            if (k-t[i] < t[j]) S[j][k-t[i]] = 0;
            if (maxValue < S[j][k-t[i]] + a[i]) maxValue = S[j][k-t[i]] + a[i];   
        }
        S[i][k] = maxValue; 
        return S[i][k];
        // S[j]][k-tj] + ai 
    }
   
}
int main() {
    cin >> N >> T >> D;
    int value;
    init();
    for (int i = 1; i <= N; i++) {
        cin >> value;
        a[i] = value;
    }
    for (int i = 1; i <= N; i++) {
        cin >> value;
        t[i] = value;
    }
    
    int max = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= T; k++) {
            if (S[i][k] == -1) {
                S[i][k] = cal(i, k);   
            }
            if (S[i][k] > max) max = S[i][k];
        } 
    }
    cout << max;
}