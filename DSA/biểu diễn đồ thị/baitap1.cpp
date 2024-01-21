#include<iostream>
using namespace std;
// danh sach canh -> ma tran ke
int main(){
    int n, m, u, v;
    cin >> n >> m;
    int a[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
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