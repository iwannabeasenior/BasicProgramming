#include<bits/stdc++.h>
#define INFI (1000000000 + 7)
using namespace std;
int n, m;
int a[10000];
int countSolution = 0;
void compute(int k, int M) {
    if (k == n) {   
        if (M % a[k] != 0) {
            return;
        } else {
            countSolution++;
            return;
        }
    }
    for (int i = 0; i <= M / a[k]; i++) {
        compute(k+1, M - i * a[k]);
    }
    return;
}       
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    compute(1, m);
    cout << countSolution;
}