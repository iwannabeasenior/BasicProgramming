#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

void thapHN(int n, char a, char b, char c) {
    if (n == 1) {
        printf("chuyen 1 coc tu %c sang coc %c\n", a, c);
        return;
    }
    thapHN(n-1, a, c, b);
    thapHN(1, a, b, c);
    thapHN(n-1, b, a, c);
}

int main (){
    
    int n;
    cout << "nhap so dia vao :";
    cin >> n;
    thapHN(n, 'A', 'B', 'C');
    // a to c , b is mid
}