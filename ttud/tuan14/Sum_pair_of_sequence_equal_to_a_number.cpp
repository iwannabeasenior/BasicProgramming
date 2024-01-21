#include<bits/stdc++.h>
#define INFI 100000000
using namespace std;
vector<vector<int>> v(10000);


// int main() {
//     int n, M;
//     cin >> n >> M;
//     int a[10000];
//     bool visited[10000];

//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//         int value = a[i] % M;
//         v[value].push_back(a[i]);
//     }
//     int dem = 0; 
//     for (int i = 1; i <= n; i++) {
//         int remainValue = M - a[i];
//         int hashCode = remainValue % M;
//         int hashCode2 = a[i] % M;
//         auto iter2 = find(v[hashCode2].begin(), v[hashCode2].end(), a[i]);
//         auto iter = find(v[hashCode].begin(), v[hashCode].end(), remainValue);
//         if (iter != v[hashCode].end()) {
//             dem++;
//             v[hashCode2].erase(iter2);
//         }
//     }
//     cout << dem;
// }
int main() {
    int n, M;
    cin >> n >> M;
    int a[n+1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int dem = 0;
    int i = 0, j = n-1;
    while (i != j) {
        if (a[i] + a[j] < M) {
            i++;
        } else if (a[i] + a[j] > M) {
            j--;
        } else {
            dem++;
            i++;
            j--;
        }
    }
    cout << dem;
}