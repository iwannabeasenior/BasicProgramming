#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dquy(int n) {
    
}
int main() {
    unordered_map <int, int> m;
    m[1] = 2;
    m[2] = 3;
    m[10] = 3;
    m[5] = 9;
    for (pair<int,int> p : m) {
        cout << p.first <<" " << p.second <<endl;
    }
}