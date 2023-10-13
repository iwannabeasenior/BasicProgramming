#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        bool a[n+1];
        for (int i = 0; i <= n; i++){
            a[i] = false;
        }
        int count = 0;
        
        for (int i=2; i*i < n; i++){
            for (int j = i*i; j <  n; j+=i){
                a[j] = true;
            }
        }
        for (int i=2; i<n; i++){
            if(!a[i]) count++;
        }

        return count;
    }
};

int main(){ 
    int n;
    cin >> n;
}