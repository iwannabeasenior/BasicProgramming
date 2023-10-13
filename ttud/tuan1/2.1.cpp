//CPP 
#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    set<int> s;
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        size_t firstSize = s.size();
        s.insert(v[i]);
        if (firstSize == s.size()) cout << 1 << endl;
        else cout << 0 << endl;
    }
}