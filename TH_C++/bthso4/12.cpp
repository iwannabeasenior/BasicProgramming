#include<bits/stdc++.h>
using namespace std;
// Nguyen Trung Thanh - 20215482

int maxArea(int a[], int n){
    int max = 0;
    int chiso = 0;
    for (int i=0; i<n; i++){
        int count_left= 0;
        int count_right = 0;
        for (int j=i-1; j>=0; j--) {
            if(a[j]>=a[i]) count_left++;
            else break;
        }
        for (int j=i+1; j<n; j++){
            if(a[j] >= a[i]) count_right++;
            else break;
        }
        if ((count_left + count_right + 1) * a[i] > max) {
            max = (count_left + count_right + 1 ) * a[i];
        }
    }
    return max;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[n];   
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // max area ...
    // find max area, 
    cout << maxArea(a, n);
}
// c2 : stack
