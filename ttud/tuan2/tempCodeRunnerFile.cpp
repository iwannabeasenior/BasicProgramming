#include<bits/stdc++.h>
#define INFI 1000000000 + 7 
using  namespace std;

int m, n;
int a[1000][1000] = {0};
long long compute(int m, int n) {
    if (m == n || m == 0) return 1;
    if (a[m][n] != 0) return a[m][n];
    else {
        a[m][n] = compute(m-1, n-1) + compute(m, n-1);
        return a[m][n];
    }
}
int main() {
    cin >> m >> n;
    cout << (compute(m, n) % INFI);

}