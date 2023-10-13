#include<bits/stdc++.h>
using namespace std;
int n; 
bool checked[10000] = {false};
vector<int> v(10000);
void permutation(int a) {
    for (int i = 1; i <= n; i++) {
        if (!checked[i]) {
            v[a] = i;
            checked[i] = true;
            if (a == n) {
                for (int j = 1; j <= n; j++) {
                    cout << v[j] <<" ";
                }
                checked[i] = false;
                cout << endl;
                return;
            } else {
                permutation(a + 1);
                checked[i] = false;
            }
        
    }
}
}
int main() {
  
    cin >> n;
    permutation(1);
    
}