#include<bits/stdc++.h>
using namespace std;

int a[9][9] = {0};
bool b[9][9] = {true};
int dem = 0;

bool checkvalid(int a[9][9], int m, int n, int value) {
    for (int i = 0; i < 9; i++) {
        if (a[i][n] == value) return false;
    }
    for (int j = 0; j < 9; j++) {
        if (a[m][j] == value) return false;
    }
    int I = m / 3;
    int J = n / 3;
    for (int i = 3*I; i < 3*(I+1); i++) {
        for (int j = 3*J; j < 3*(J+1); j++) {
            if (a[i][j] == value) return false;
        }
    }
    return true;
}

void sodoku(int a[9][9], int m, int n) {
    
    // find m, n sao cho b[m][n] = false
    while (true) {
        if (b[m][n]) {
            if (n < 8) n++;
            else if (m < 8) {
                m++;
                n = 0;
            } else {
                dem++;
                return;
            }
        }
        else break;
    }
        int x = m;
        int y = n;
        for (int i = 1; i <= 9; i++) {
            if (checkvalid(a, m, n, i)) {
                a[m][n] = i;
                if (m == 8 && n == 8) {
                    dem++;
                    // for (int i = 0; i < 9; i++) {
                    //    for (int j = 0; j < 9; j++) {
                    //         cout << a[i][j] << " ";
                    //     }
                    //     cout << endl;

                    // } 
                    a[m][n] = 0;
                    return;
                } else if (n < 8) {
                    sodoku(a, m, n+1);
                    m = x;
                    n = y;
                    a[m][n] = 0;
                } else {
                    
                    sodoku(a, m+1, 0);
                    m = x;
                    n = y;
                    a[m][n] = 0;
                }
                // find element that match condition
                // if (n < 8){
                //    for (int y = n+1; y <= 8; y++) {
                //         if (!b[m][y]) {
                //             sodoku(a, m, y);
                //             a[m][n] = 0;
                //         }
                //     } 
                // }
                // if (m == 8 && n == 8) {
                //     dem++;
                //     a[m][n] = 0;
                //     return;
                // }
                // for (int x = m+1; x <= 8; x++) {
                //     for (int y = 0; y <= 8; y++) {
                //          if (!b[m][y]) {
                //             sodoku(a, m, y);
                //             a[m][n] = 0;
                //         }
                //     }
                // }
                // if (m == 8 && n == 8) {
                //     dem++;
                //     a[m][n] = 0;
                //     return;
                // }
                    
            }
        }
    }


int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            b[i][j] = true;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) b[i][j] = false; 
        }
    }
    
    sodoku(a, 0, 0);
    cout << dem;
}