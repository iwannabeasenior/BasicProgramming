#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<set>
#include <algorithm>
#define MAX_INTERGER 2147483648
using namespace std;

// a[i] = (a[i-1] * p + q) % 2^31 = 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    set<int> set;
    int x = s % MAX_INTERGER;
    set.insert(x);
    
    for (int i=1; i<n; i++){
        x = (x * p + q) % MAX_INTERGER;
        set.insert(x);
    }
    
    cout << set.size();
    return 0;
}