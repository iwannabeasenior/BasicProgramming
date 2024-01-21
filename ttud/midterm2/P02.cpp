#include<iostream>
#include<vector>
using namespace std;
int n, m;
int d[10000][10000];
int a[10000];
int totalDistance = 0;
bool vistied[10000] = {false};
// bool constraint[10000][10000];
vector<vector<int>> constraint(10000);

bool check() {
    for(int i = 1; i <= n; i++) {
        for (int k : constraint[a[i]]) {
            if (vistied[k]) {
                return false;
            }
            vistied[a[i]] = true;
        }
    }
    return true;
}
int checkAndCompute() {
    for (int i = 2; i <= n; i++) {
        totalDistance += d[a[i-1]][a[i]];
    }
    return totalDistance;
}
int main() {
    cin >> n;
    // for (int i = 1; i < 10000; i++) {
    //     for (int j = 1; j < 10000; j++) {
    //         d[i][j] = 0;
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    cin >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        constraint[x].push_back(y);
    }

    if (check()) {
        cout << checkAndCompute() + d[a[n]][a[1]];
    } else {
        cout << -1;
    }
  
}