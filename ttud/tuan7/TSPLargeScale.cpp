// gready
#include<bits/stdc++.h>
using namespace std;
int n;
int cost = 0;
int a[1005][1005];
bool visited[1005];
int path[1005];
int path2[1005];
vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> edges(1000);

void reverseArray(int arr[], int start, int end) 
{ 
    while (start < end) 
    { 
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}  
bool opt() {
    for (int i = 1; i <= n-2; i++) {
        for (int j = i+2; j <= n; j++) {
            if (i == 1 && j == n) {
                break;
            }
            int costMiddleBefore = 0;
            for (int k = i+1; k <= j-1; k++) {
                costMiddleBefore += a[path[k]][path[k+1]];
            }
            int costMiddleAfterReverse = 0;
            for (int k = j; k > i+1; k--) {
                costMiddleAfterReverse += a[path[k]][path[k-1]];
            }
            int newCost = cost - a[path[i]][path[i+1]] - a[path[j]][path[j+1]] + a[path[i]][path[j]] + a[path[i+1]][path[j+1]] - costMiddleBefore + costMiddleAfterReverse;            
            if (newCost < cost) {
                cost = newCost;
                // updateee
                int x = path[i+1];
                int y = path[j];
                path[i+1] = y;
                path[j] = x; 
                if (j > i+3)
                reverseArray(path, i+1+1, j-1);
                return true;
            }
        }
    }
    return false;
}
int main() {
     cin >> n;   
    int value;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> value;
            a[i][j] = value;
            if (i != j) {
                edges[i].push({value, j});
            }
        }
    }
    path[1] = 1;
    int dem = 1;

    int prev = 1;
    visited[1] = true;
    while(dem < n) {
        while (!edges[prev].empty()) {
            auto top = edges[prev].top();
            if (!visited[top.second]) {
                dem++;
                path[dem] = top.second;
                cost += top.first;
                prev = top.second;
                visited[top.second] = true;
                break;
            } else {
                edges[prev].pop();
            }
        }
    }
    cost += a[prev][1];
    
    path[n+1] = 1;
    int dems = 0;
    while (true) {
        if (opt()) {
            dems++;
            if (dems == 7) {
                break;
            }
        } else {
            break;
        }
    }
    cout << n << endl;
    // cout << cost << endl;
    for (int i = 1; i <= n; i++) {
        cout << path[i] << " ";
    }
    // has path and cost
    // 2 opt
    // find 2 edges not ke nhau, dau noi dau, duoi noi duoi, 
    // gia su 1,2,3,4,5,6,1 => chon (1,2), (5,6) => 1,5,4,3,2,6,1 => newDistance = oldDistance - d[old1]-d[old2] + d[new1] + d[new2];
}
 