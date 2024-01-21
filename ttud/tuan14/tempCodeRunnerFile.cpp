#include<bits/stdc++.h>
#define INFI 10000000
using namespace std;

int n;
int a[100001];
int maxVal[100001];
int getMax(int id, int L, int R, int i, int j) {
    if (i > R || i < L) return -INFI;
    if (i <= L && j >= R) return maxVal[id];
    int m = (L+R)/2;
    int LC = 2*id; int RC = 2*id + 1;
    int maxLeft = getMax(LC, L, m, i, j);
    int maxRight = getMax(RC, m+1, R, i, j);
    return max(maxLeft, maxRight);
}
void upDate(int id, int L, int R, int i, int v) {
    if (i < L || i > R) {
        return;
    } 
    if (L == R) {
        maxVal[id] = v;
        return;
    }
    int m = (L+R)/2;
    upDate(id*2, L, m, i, v);
    upDate(id*2+1, m+1, R, i, v);
    maxVal[id] = max(maxVal[id*2], maxVal[id*2+1]);
}
void proprocessing(int id, int L, int R) {
    if (L == R) {
        maxVal[id] = a[L];
        return;
    }
    int m = (L+R)/2;
    proprocessing(id*2, L, m);
    proprocessing(id*2+1, m+1, R);
    maxVal[id] = max(maxVal[id*2], maxVal[id*2+1]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // tien xu li maxVal
    proprocessing(1, 1, n);
    for (int i = 1; i <= 20; i++) {
        cout << maxVal[i] << endl;
    }
    int q;
    cin >> q;
    string query;
    int x, y;
    for (int i = 1; i <= q; i++) {
        cin >> query;
        if (query == "get-max") {
            cin >> x >> y;
            cout << getMax(1, 1, n, x, y);
        } else {
            cin >> x >> y;
            upDate(1, 1, n, x, y);
        }
    }
}