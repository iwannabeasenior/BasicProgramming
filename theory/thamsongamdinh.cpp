#include<iostream>
using namespace std;
void myfunction(int n=1000)
    {
        printf("%d",n);
    }
void Myfunction(int a,int b=1){
    printf("hello world");
}
int main(){
    myfunction();
    myfunction(5000);
    Myfunction(1,1000);
}