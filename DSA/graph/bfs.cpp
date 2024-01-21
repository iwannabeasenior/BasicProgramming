#include<bits/stdc++.h>
// bfs dung danh sach ke
// do thi khong co trong so -> thuat toan bfs tim dc duong di ngan nhat tu 1 dinh den dinh khac
using namespace std;
int n, u, v;
vector<int> edge[100];
queue<int> q;
bool visited[100]={false};
void BFS(int dinh){
    q.push(dinh);
    visited[dinh] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i : edge[v]){
            if (!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }    
    BFS(1);
    
}