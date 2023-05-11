#include<iostream>
using namespace std;
void myfunction(int n){
    printf("hello world 1");
}
int  myfunction(double a){
    printf("hello world 2");
    return 0;
    // return "hello world 2";
}

int main(){
    cout<< "hello world";
    myfunction(10);
    myfunction(1.21);
}
