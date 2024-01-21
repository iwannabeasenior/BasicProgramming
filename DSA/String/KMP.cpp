#include<bits/stdc++.h>
#define N 1000
using namespace std;
string source, pattern;
int pi[N];
void compute() {
    int m = pattern.length();
    pi[1] = 0;
    int k = 0;
    int prev = 0;
    int dem = 0;
    for (int i = 2; i <= m; i++) {
        if (pattern[i-1] == pattern[prev]) {
            dem++;
            pi[i] = dem;
            prev++;
        } else {
            dem = 0;
            if (pattern[i-1] == pattern[0]) {
                dem++;
                pi[i] = dem;
                prev = 1;
            } else {
                pi[i] = 0;
            }
        }
    }
}
int main() {
    cin >> pattern >> source;
    int m = pattern.length();
    int n = source.length();
    compute();
    int s = 0;
    int start = 0;// chi vi tri xuat phat trong P
    while (s <= n-m) {
        int dem = 0;
        int k = start;
        while (k < m) {
            if (source[k+s] == pattern[k]) {
                k++;
            } else {
                // k la so phan tu chung cua 2 day dang so sanh
                if (k == 0) {
                    start = 0;
                    s++;
                }
                else {
                    start = pi[k];
                    s += k - pi[k];
                }
                break;
            }
            if (k == m) {
                cout << "tim thay pattern o vi tri : " << s << endl;
                start = pi[k];
                s += k-pi[k];
                break;
            }
        }
        
    }
}