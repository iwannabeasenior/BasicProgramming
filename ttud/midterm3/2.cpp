#include<bits/stdc++.h>
#define Q (1000000000+7)
typedef long long ll;
using namespace std;

int n;
int main() {
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n-1);
    vector<ll> c;
    vector<ll> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (b[i] != 2 ){
            c.push_back(a[i]);
            d.push_back(b[i]);
            if (i == n-2) {
                c.push_back(a[i+1]);
                break;
            }
        } else {
            ll sum = a[i];
            i++;
            while (b[i] == 2 && i < n-1) {
                sum *= a[i];
                i++;
            }
            sum *= a[i];
            c.push_back(sum);
            if (i < n-1) {
              d.push_back(b[i]);
              if (i == n-2) {
                c.push_back(a[i+1]);
                break;
              } 
            } else {
                break;
            }  
        }
    }

    ll sum = c[0];
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0) {
            sum -= c[i+1];
        } else if (d[i] == 1) {
            sum += c[i+1];
        }
    }
    cout << sum % Q;
}   