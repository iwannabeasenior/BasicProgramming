#include<bits/stdc++.h>
using namespace std;
int t;

// quay lui xet tat ca cac dinh xem nhu nao

void checkHamilton(vector<vector<int>> edges, bool visited[], int k, int dem, int start, int n, int& dem1) {
    for (int i : edges[k]) {
        if (!visited[i]) {
            visited[i] = true;
            dem++;
            if (dem == n) {
                for (int j : edges[i]) {
                    if (j == start) {
                        dem1++;
                    }
                }
            } else {
                checkHamilton(edges, visited, i, dem, start, n, dem1);
            }
            visited[i] = false;
            dem--;
        }
    }
}
int main() {

    int n, m, u, v;
    cin >> t;

    while (t--) {

        cin >> n >> m;
        vector<vector<int>> edges(1001); // danh sach ke 
        bool vistited[1001];
        int dem1 = 0;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        

        for (int i = 1; i <= n; i++) {
            int dem = 1;
            vistited[i] = true;
            checkHamilton(edges, vistited, i, dem, i, n, dem1);
            if (dem1) {
                cout << 1 << endl;
                break;
            }
            vistited[i] = false;
        }
        if (!dem1) cout << 0 << endl;
    }

}