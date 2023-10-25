#include<bits/stdc++.h>
using namespace std;
int number, n, m;
int main() {
    cin >> number;
    while (number--) {
        cin >> n >> m;
        vector<int> edges[1000];
        int count[1000] = {0};
        bool visited[1000][1000];
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                visited[i][j] = false;
            }
        }
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
            count[a]++;
            count[b]++;
            visited[a][b] = true;
            visited[b][a] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && !visited[i][j]) {
                    if (count[i] + count[j] < n) {
                        cout << "0" << endl;
                        goto lable;
                    }
                    visited[i][j] = true;
                    visited[j][i] = true;
                }
            }
        }
        cout << "1" << endl;
        lable : 1;
    }
}