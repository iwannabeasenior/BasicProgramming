#include<bits/stdc++.h>
using namespace std;
int cMin = 1000;
bool visited[50];
int load = 0;
int K, n;
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
            if (k == 2*n) solution();
            else{
                if (f + cMin * (2*n + 1-k) < record)
                Try(k+1);
            }
            visited[v] = false;
                f = f - c[x[k-1]][x[k]];
                if (v <= n) load -=1; else load += 1;
        }
    }
}
int main() {
    for (int i =0; i < 50; i++) {
        visited[i] = false;
    }
   cin >> n >> K;
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
