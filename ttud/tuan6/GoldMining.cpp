#include<bits/stdc++.h>
using namespace std;
int n, l1, l2;
int a[1000000] = {0};
int gold[1000000];
int goldMining(int k) {
    if (gold[k] == -1) {
        if (k <= l1) {
            gold[k] = a[k];
            return gold[k];
        }
        int max = 0;
        int start;
        if (k-l2 >= 1) start = l2;
        else start = k-1;
        for (int i = start; i >= l1; i--) {
            if (gold[k-i] == -1) gold[k-i] = goldMining(k-i);
            if (max < gold[k-i] + a[k]) max = gold[k-i] + a[k];
        }
        return max;
    }
    else {
        return gold[k];
    } 
}
int main() {
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 1000000; i++) {
        gold[i] = -1;
    }
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (gold[i] == -1) gold[i] = goldMining(i);
        if (gold[i] > max) max = gold[i];
    } 
    cout << max;  
}