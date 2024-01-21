#include<bits/stdc++.h>
#define INFI (1000000000 + 7)
using namespace std;
int N;
int a[10000];
int compute(int k) {
    if (k == 0) return 1;
    else if (k == 1) return 3;
    if (a[k-1] == 0) a[k-1] = compute(k-1) % INFI;
    if (a[k-2] == 0) a[k-2] = compute(k-2) % INFI;
    return (2*a[k-1] % INFI + a[k-2] % INFI) % INFI;
}
int main() {
    cin >> N;
    cout << compute(N);
}