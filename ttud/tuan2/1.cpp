#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v(1000);
void bsg(int a) {
    for (int i = 0; i <= 1; i++) {
        v[a] = i; 
        if (a == n) {
            for (int j = 1; j <= n; j++) {
                cout << v[j];
            }
            cout <<""<<endl;
            continue;
        } else {
            bsg(a+1);
        }
    }
   
}
int main() {
    cin >> n;
    bsg(1);
}