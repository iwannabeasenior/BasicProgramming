#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long a, b, a1, a2, b1, b2, ab1, ab2, c1, d1  = {0};
    cin >> a >> b;
    a2 = a % 10;
    b2 = b % 10;
    a1 = a/10;
    b1 = b/10;
    ab1 = a1 + b1;
    ab2 = a2 + b2;
    if (ab2 >= 10) {
        c1 = ab2/10;
        d1 = ab2%10;
        ab1 += c1;
        cout << ab1 << d1;
    } else {
        if (ab1 == 0) cout << ab2;
        else cout << ab1 << ab2;
    }
    
    
}