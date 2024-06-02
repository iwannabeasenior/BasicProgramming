// giai bai 2
#include<bits/stdc++.h>
using namespace std;
int cMin = 1000;
bool visited[50];
//
int maxDistance[50] = {0};
bool onBus[50] = {false};
//
int load = 0;
int K, n, D;
int c[50][50];
int x[50];
int f = 0;
int record = 1000;
bool check(int v, int k) {
    if (visited[v] == true) return false;
    if (v <= n) {
        if(load >=K ) return false;
        // if(visited[n+v] == true) return false;

    }else {
        if(visited[v-n] == false) return false;
    }

    for (int i = 1; i <= n; i++) {
        if (onBus[i] && c[x[k-1]][v] + maxDistance[i] > D) {
            return false;
        }   
    }
    
    
    return true;
}
void solution() {
    if (f + c[x[2*n]][0] < record) record = f + c[x[2*n]][0];
}
void Try(int k) {
    for (int v = 1; v <= 2*n; v++) {
        if(check(v,k)) {
            x[k] = v;
            visited[v] = true;
            f = f + c[x[k-1]][x[k]];
            if (v <= n) load += 1; else load -= 1;
            // max Distance on each passenger
            for (int i = 1; i <= n; i++) {
                if (onBus[i]) {
                    maxDistance[i] = c[x[k-1]][v] + maxDistance[i];
                }
            }
            if (v <= n) {
                onBus[v] = true;
            } else {
                onBus[v-n] = false;
            }
            
            if (k == 2*n) solution();
            else{
                if (f + cMin * (2*n + 1-k) < record)
                Try(k+1);
            }
            visited[v] = false;
            f = f - c[x[k-1]][x[k]];
            if (v <= n) {
                onBus[v] = false;
                maxDistance[v] = 0;
            } else {
                onBus[v] = true;
                maxDistance[v] = maxDistance[v] - c[x[k-1]][v];
            }
            if (v <= n) load -=1; else load += 1;
        }
    }
}
int main() {
    for (int i =0; i < 50; i++) {
        visited[i] = false;
        maxDistance[i] = 0;
        onBus[i] = false;
    }
   cin >> n >> K >> D;
   x[0] = 0;
   int value;
   for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> value;
            c[i][j] = value;
            if (value < cMin) cMin = value;
        }
   }
   Try(1);
   cout << record;
}
