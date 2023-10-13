#include <iostream>
//Nguyen Trung Thanh -20215482
using namespace std;

int x_or(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum^a[i];
    }
    return sum;
}
int main(){
    int n;
    int m;
    cin>>n;
    int a[n+1];
    
    for (int  i = 0; i < n+1; i++)
    {
        /* code */
        cin>>a[i];
    }

    cin>>m;
    int b[m+1];
    
    for (int  i = 0; i < m+1; i++)
    {
        /* code */
        cin>>b[i];
    }
    int c[n+m+1]={0};
    
    for(int i=0;i<n+m+1;i++){
        for(int j=0;j<=n;j++){
            int k=i-j;
            if(k>=0 && k<=m){
               c[i]+=a[j]*b[k]; 
            }
           
        }
    }
    int sum=0;
    for(int i=0;i<n+m+1;i++){
        sum=sum^c[i];
    }
    cout<<sum;
}