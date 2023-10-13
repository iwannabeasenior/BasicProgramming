#include<bits/stdc++.h>
using namespace std;
int n, M;
vector<int> v(10000);
void generate(int a) {
    for (int i = 1; i <= (M - (n - a - 1)) ; i++) {
        v[a] = i;
        M = M - i;
        if (a == n - 2) {
            v[a+1] = M;
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            M = M + i;
            continue;
            
        }
        else {
            generate(a + 1);
            M = M + i;
        }
    }
    return;
}
int main() {
    
    cin >> n >> M;
    generate(0);
}