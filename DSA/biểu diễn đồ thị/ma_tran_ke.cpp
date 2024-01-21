#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "nhap so canh cua do thi:";
    cin >> n;
    //khoi tao ma tran bieu dien do thi
    int **a = new int*[n];
    for (int i = 0; i < n; i++){
        a[i] = new int [n];
    }
    // đồ thị vô hướng nên a[i, j] = a[j, i]
    a[1][1] = 0;
    //......
    // tương tự cho ma trận trọng số 
}