#include<bits/stdc++.h>
#define MAX_VALUE (unsigned long long)(1e9 + 7) 
using namespace std;
// unsigned long long nhan(unsigned long long t) {
//     for (unsigned long long i = 1; i < t; i++) {

//     }
// }
unsigned long long  exp(unsigned long long a, unsigned long long b) {
    if (b == 1) {
        return a % MAX_VALUE;
    }
    unsigned long long  c = b/2;
    unsigned long long T = exp(a,c) % MAX_VALUE;
    if (b % 2) return ((T * T) % MAX_VALUE * (a % MAX_VALUE) ) % MAX_VALUE;
    else return (T * T) % MAX_VALUE;
}
int main() {
    unsigned long long  a, b; cin >> a >> b;
    cout << exp(a, b);
}