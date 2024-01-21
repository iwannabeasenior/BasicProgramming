#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// danh sach ke -> ma tran ke
int main(){
    int n;
    // nhap so dinh
    cin >> n;
    cin.ignore();
    int a[n+1][n+1] = {0};
    
    for (int i = 1; i <= n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num){
            a[i][stoi(num)] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    


}