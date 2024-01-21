#include<bits/stdc++.h>
#define N 1000
using namespace std;
string source, pattern;
int n,m;
int t[N];

bool check(int i) {
    for (int j = 0; j < m; j++) {
        if (source[i+j] != pattern[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> pattern >> source;
    m = pattern.length();
    n = source.length();
    int p = 0;
    int q; cin >> q;
    for (int i = 0; i < m; i++) {
        p = (2*p + pattern[i]) % q ;
        cout <<"gia tri cua p la : " <<  p << endl;
    }
    t[0] = 0;
    int offset = 1;
    for (int i = 0; i < m-1; i++) {
        offset = (offset*2) % q;
    }
    offset = offset % q;
    // offset = pow(2, m-1);
    for (int i = 0; i < m; i++) {
        t[0] = (2*t[0] + source[i]) % q ;
    }

    cout << t[0] << endl;

    for (int i = 1; i < n-m+1; i++) {
        t[i] = (2 * (t[i-1] - offset * source[i-1]) + source[i+m-1]) % q;
        while (t[i] < 0) {
            t[i] = t[i] + q; 
        }
    }

    for (int i = 0; i < n-m+1; i++) {
        if (t[i] == p && check(i)) {
            cout << "pattern duoc tim thay o vi tri " << i << endl;
        } else {
            cout <<"not found o vi tri " << i << endl;
        }
    }
    
}