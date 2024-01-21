#include<iostream>
#include<vector>
using namespace std;
// ma tran ke -> danh sach canh
vector<pair<int, int>> edge;

int main(){
    int n;
    cin >> n;   
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    for (int  i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if(a[i][j]){
                edge.push_back({i,j});
            }
        }
    }
    for(pair<int, int> p : edge){
        cout << p.first << " " << p.second << "\n";
    }
    
}