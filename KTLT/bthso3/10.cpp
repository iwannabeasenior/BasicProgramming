#include<bits/stdc++.h>
using namespace std;
struct state{
    int i, j;
    state(int _i = 0, int _j = 0) : i(_i), j(_j) {}
};
int main(){
    int n, h;
    cin >> n >> h;
    int dem_h = 0;
    stack<state> s;
    s.push(state(1, 0));
    int x[n + 1];
    while (!s.empty()){
        state& top = s.top();
        if (top.i > n){
            if(dem_h == h){
               for (int i = 1; i <= n; i++)
                    {
                         cout << x[i] << " \n" [i == n];
                    } 
            }
            
            s.pop();
            continue;
        }
        if(top.j > 1){
            dem_h --;
            s.pop();
            continue;
        }
        if(dem_h + 1 <= h || top.j == 0){
            x[top.i] = top.j;
            if (top.j){
                dem_h++;
            }
            s.push(state(top.i + 1, 0));

        }
        top.j++;
    }
}