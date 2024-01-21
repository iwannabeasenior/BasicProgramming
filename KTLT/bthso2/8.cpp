#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include<bits/stdc++.h>
using namespace std;
// Nguyen Trung Thanh-20215482
bool comp(const vector<int> x, const vector<int> y){
    int a=0;
    int b=0;
    for(int i: x){
        a+=i;
    }
    
    for(int i: y){
        b+=i;
    }
    return a>b;
    
}
int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    sort(a.begin(),a.end(),comp);
       
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}