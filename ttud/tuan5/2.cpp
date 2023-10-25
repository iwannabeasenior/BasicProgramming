#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int maxWeight = -10000;
int SumPast;
int SumCurrent;
int main() {
    cin >> n;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
    SumPast = v[0];
    for (int i = 1; i < n; i++) {
        if (SumPast < 0) {
            SumCurrent = v[i];
            SumPast = SumCurrent;
            if (SumCurrent > maxWeight) maxWeight = SumCurrent;
        } else {
            SumCurrent = v[i] + SumPast;
            SumPast = SumCurrent;
            if (SumCurrent > maxWeight) maxWeight = SumCurrent;
        }
         
    }
    cout << maxWeight;
}