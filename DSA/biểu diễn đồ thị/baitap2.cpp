#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// danh sach canh -> danh sach ke
int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<int> vt[n + 1];
    for (int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":";
        for(int k : vt[i]){
            cout << k << " ";
        }
        cout << "\n";
    }
}