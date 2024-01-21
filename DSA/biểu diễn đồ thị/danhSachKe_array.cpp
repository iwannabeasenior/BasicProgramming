#include<iostream>
using namespace std;

#define NMAX 100
#define MMAX 1000

/*
Trước tiên bạn chỉ cần hiểu các đỉnh kề của đỉnh u là Adj[v] với v=Head[u]+1……Head[u+1]
*/

//Khai báo dữ liệu
// n là số đỉnh , m là số cạnh  
int x[MMAX], y[MMAX], Head[NMAX+2], Adj[MMAX+1];
int n, m, u, v;
int main(){
    // Đọc dữ liệu
    cin >> n >> m;
    
    // Gán Head[i]=0
    for (int i=0; i<=n+1; i++)
        Head[i]=0;
    
    for (int i=1; i<=m; i++)
    {
        cin >> x[i] >> y[i];
        Head[x[i]]++;
    }
    
    for (int i=2; i<=n+1; i++)
        Head[i]=Head[i-1]+Head[i];
    
    for (int i=1; i<=m; i++)
    { 
        Adj[Head[x[i]]]=y[i];
        Head[x[i]]--;
    }
} 