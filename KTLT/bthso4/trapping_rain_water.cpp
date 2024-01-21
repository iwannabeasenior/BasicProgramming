#include<bits/stdc++.h>
using namespace std;

int tongLuongNuoc(int a[], int n){
    int tongNuoc = 0;
    int i = 0;
    bool flag  = false;
    while (!flag){
        for (int j = i + 1; j < n; j++){
        if (a[j] >= a[i]){
            for (int k = i + 1; k < j ; k++){
                tongNuoc += a[i] - a[k];
            }
            i = j;
            goto xx;
        }
        }
        flag = true;
        xx : cout << "";
    }

    bool flag2 = false;
    int k = n - 1;
    while (!flag2){
        for (int m = k - 1; m >= i ; m--)
        {
            if (a[m] >= a[k]){
                for (int z = k - 1; z > m; z--){
                   tongNuoc += a[k] - a[z];
                }
                k = m;
                goto x; 
            }
            
        }
        flag2 = true;   
        x : cout << "";
    }
    return tongNuoc;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout << tongLuongNuoc(a, n);
}