#include<iostream>
using namespace std;
typedef struct sp{
    int real;
    int img;
} sp;
sp operator + (sp a,sp b){
    sp c;
    c.img=a.img+b.img;
    c.real=a.real+b.real;
    return c;
}
    
int main(){
    sp a;
    a.real=1;
    a.img=2;
    sp b;
    b.real=2;
    b.img=3;
    sp c=a+b;
    cout<<c.real<<"+"<<c.img<<endl;
}