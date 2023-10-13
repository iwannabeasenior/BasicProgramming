#include<bits/stdc++.h>
using namespace std;
int x[9][9];
bool markR[9][10];
bool markC[9][10];
bool markS[3][3][10];
bool check(int v, int r, int c) {
    return markR[r][v] == false

}
void Try(int r, int c) {
    for (int v = 1; v <= 9; v++) {
        if (check(v,r,c)) {
            X[r][c] = v;
            markR[r][v] = true;
            markC[c][v] = true;
            if (r == 8 && c == 8) solution();
            else {
                if (c==8) Try(r+1, 0); else Try(r, c+1);
            }
        }
        markR[r][v] = false;
        markC[r][v] = false;
        markS[r/3][c/3][v] = false;
    }
}
int main() {
    for (int v = 1; v <= 9; v++) {
        for (int r = 0; r <= 8; r++) markR[r][v] = false;
        for (int c= 0; c <= 9; c++) markC[c][v] = false;
        
    }    
}