#include<bits/stdc++.h>
//Run a loop to traverse through the rows.
// Now If the current row is not the first row then update the row as follows, if matrix[i][j] is not
//  zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j].
// Find the maximum rectangular area under the histogram, 
// consider the ith row as heights of bars of a histogram. 
// This can be calculated as given in this article Largest Rectangular Area in a Histogram
// Do the previous two steps for all rows and print the maximum area of all the rows.
using namespace std;
int n, m;
int record = 0;
int a[10001][10001];
bool check(int b, int c, int d) {
    for (int i = b; i <= c; i++) {
        if (a[d][i] == 0) return false;
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cd = j-i+1;
            int current = 0;
            int maxCurrent = 0;
            for (int k = 1; k <= m; k++) {
                if (check(i, j, k)) {
                    current++;
                } else {
                    if (current > maxCurrent) maxCurrent = current;
                    current = 0;
                }
            }
            if (current > maxCurrent) maxCurrent = current;
            if (maxCurrent * cd > record) record = maxCurrent * cd;
        }
    }
    cout << record;
}