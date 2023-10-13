#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v(1000);
void bsg(int a) {
    
    for (int i = 0; i <= 1; i++) {
        if (v[a-1] == 1 && i == 1) continue;
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
    // clock_t start = clock();
    bsg(1);
    // clock_t end = clock();
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << time_taken;
}