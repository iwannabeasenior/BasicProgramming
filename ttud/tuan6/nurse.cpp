#include<bits/stdc++.h>
using namespace std;
int  N, K1, K2, K3;
int S1[1000] = {0};
int S0[1000] = {0};
// find S0[N] va S1[N]
int process1(int k);
int process0(int k) {
    if (k == 1) return 1;
    else if (k == 0) return 1;
    else if (k <= K1) return 0;
    else if (S1[k-1] == 0) {
        S1[k-1] = process1(k-1);
    } 
    return S1[k-1];
}
int process1(int k) {
    if (k == K1) return 1;
    else if (k < K1) return 0;
    else {
        int sum = 0;
        int start;
        if (k-K2 > 0) start = k - K2;
        else start = 0;
        for (int i = start; i <= k-K1; i++) {
            if (S0[i] == 0) {
                S0[i] = process0(i);
            }
            sum += S0[i];
        }
        return sum;
    }
}

int main() {
    cin >> N >> K1 >> K2;
    cout << process0(N) + process1(N);
}