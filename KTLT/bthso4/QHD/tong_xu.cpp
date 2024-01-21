#include<iostream>
using namespace std;
int main(){
    int n, tong;
    cin >> n >> tong;
    int a[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int f[tong+1] ;
    for (int i = 0; i <= tong; i++)
    {
        f[i] = 100000;
    }
    
    f[0] = 0;
    for (int i = 1; i <= tong; i++){
        for (int j = 0; j < n; j++){
            if (a[j] <= i){
                if(f[i] > f[i-a[j]] + 1){
                    f[i] = f[i-a[j]] + 1;
                }
            }
        }
    }
    cout << f[tong];
    
}