#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct state{
    int i, j, _0, _1;
    state(int _i = 0, int _j = 0, int _old0 = 0, int _old1 = 0):i(_i), j(_j), _0(_old0), _1(_old1){}
};
// 0 : 2, k1 <= 1 <= k2

int main(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    stack<state> s;
    int x[n+1];
    int _0 = 0;
    int _1 = 0;
    s.push(state(1, 0, 0, 0));
    while(!s.empty()){
        state& top = s.top();
        if (top.i > n ){
            for (int q = 1; q <= n; q++)
            {
                cout << x[q] << " \n" [q==n];
            }
            s.pop();
            continue;
        }
        if (top.j < 1){
            _1 = top._1;
            _0 = top._0;
        }
        if (top.j < 0){
            s.pop();
            continue;
        } 

        if((_1 + 1 <= k2 && top.j == 1) || ((_0 + 1 < 2) && top.j == 0 )){
            x[top.i] = top.j;
            top._0 = _0;
            top._1 = _1;
            if (top.j){
                _1++;
                _0 = 0;
            }
            else{
                _0++;
                _1 = 0;
            } 
            s.push(state(top.i + 1, 1));
        }
        
        top.j--;
    }
}