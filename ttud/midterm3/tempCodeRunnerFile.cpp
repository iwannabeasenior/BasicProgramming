#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = 0, dem = 0;
    while (i < n && j < n) {
        int sub = v[j]-v[i];
        if (sub == 1) {
            int c = 1;
            dem++;
            int k = i+1;
            while (k < n && k < j) {
                if (v[j] - v[k] == 1) {
                    i = k;
                    k++;
                    dem++;
                    c++;
                } else { 
                    break;
                }
            }
            int k = j+1;
            int t = 0;
            while (k < n) {
                if (v[k] - v[i] == 1) {
                    t++;
                    k++;
                } else {
                    break;
                }
            }
            dem += c*t;
        } else if (sub < 1) {
            j++;
        } else if (sub > 1) {
            i++;
        }
    }
    cout << dem;
}