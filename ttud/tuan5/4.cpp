#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
    long long Even[1000000];
    long long Odd[1000000];
    long long maxValue = -10000;
int main() {
    int n; cin >> n;
    
    for (int i = 0; i < 1000000; i++) {
        Even[i] = -1000000;
        Odd[i] = -1000000;
    }
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }   
    if (v[0] % 2 == 1) Odd[0] = v[0];
    else Even[0] = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] % 2 != 0) {
            if (Even[i-1] != -1000000 && Even[i-1] > 0) {
                Odd[i] = Even[i-1] + v[i];
            } else {
                Odd[i] = v[i];
            }
            if (Odd[i-1] != -1000000 ) {
                Even[i] = Odd[i-1] + v[i];
            } 
            
        } else {
            if (Even[i-1] != -1000000 && Even[i-1] > 0) {
                Even[i] = Even[i-1] + v[i];
            } else {
                Even[i] = v[i];
            }
            if (Odd[i-1] != -1000000) {
                Odd[i] = Odd[i-1] + v[i];
            } 
        }
        if (Even[i] > maxValue) maxValue = Even[i];
    }
    cout << maxValue;
}