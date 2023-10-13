#include<bits/stdc++.h>
using namespace std;
int n ;
vector<long long> v(1000);
long long fibo(int n) {
    if (n == 0 ) return 0;
    else if (n == 1) return 1;
    else {
        if (v[n] != 0) return v[n];
        else {
            v[n] = fibo(n-1) + fibo(n-2);
            return v[n];
        }
    }
}
int main() {
    cin >> n;
    cout << fibo(n-1);
}