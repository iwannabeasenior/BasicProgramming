#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int** a = new int*[n+1];
    for (int i = 1; i <= n; i++){
        a[i] = new int [n + 1];
    }
    // do thi co huong
    /*
    {
        1 , nếu đỉnh i là đỉnh đầu của cung ej
        -1, nếu đỉnh i là đỉnh cuối của cung ej
        0, nếu đỉnh i không là đầu mút của cung ej
    }
    */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
}