#include<bits/stdc++.h>
using namespace std;
// dfs dung danh sach ke
int n, u, v;
vector<int> edge[100];
bool visited[100];
void khoiTao(bool* visited){
    memset(visited, false, sizeof(visited));
}
void DFS(int dinh){
    visited[dinh] = true;
    cout << dinh << "\n";
    for (int i : edge[dinh]){
        if (!visited[i]){
            DFS(i);
        }
    }
}
int main(){
    
    // nhap so canh
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    khoiTao(visited);
    // nhap dinh can duyet
    int dinh ;
    cin >> dinh;
    DFS(dinh);

}