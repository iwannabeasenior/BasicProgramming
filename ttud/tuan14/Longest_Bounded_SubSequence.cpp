#include<bits/stdc++.h>
using namespace std;
int n, M; 
int a[1000001];
int sum = 0;
int maxValue() {
    // int i = 1, j = n;
    // int value;
    // while (i <= j) {
    //     if (sum > M) {
    //         sum -= max(a[i], a[j]);
    //         if (a[i] > a[j]) i++;
    //         else j--;
    //     } else if (sum <= M) {
    //         return j - i + 1;
    //     }
    // }
    // return -10000;
    int res = 0;
    int L = 1;
    int S = 0;
    for (int R = 1; R <= n; R++) {
        S = S + a[R];
        while (S > M) {
            S = S - a[L]; L++;
        }
        res = max(res, R-L+1);
    }
    return res;
}
int main() {
    cin >> n >> M;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int maxValueReturn = maxValue();
    if (maxValueReturn == 0) {
        cout << -1;
    } else cout << maxValueReturn;
}