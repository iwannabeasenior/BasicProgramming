#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class A{
    int b;
    public: 
    int a;
    A(int x): a(x){};
    A(){};
    bool operator < (const A & other){
        if(other.a > a) return true;
        else return false;
    }
    bool compareInner(const A & other){
        if(other.a > a) return true;
        else return false;
    }  
    // khong can truyen vao comparator khi sort nua
};

bool compare(const A& x, const A& y){
    if(x.a > y.a) return false;
    else return true;
}

int main(int argc, char const *argv[])
{
    A*str = new A[5];  
    //ok
    sort(str,str+5,greater<A>());   
    //ok
    sort(str,str+5);
    //ok
    sort(str,str+5,compare);
    //ok
    sort(str,str+5,[](const A& x, const A& y)->bool
    {
        if(x.a > y.a) return false;
        else return true; 
    });

    // ?? 
    A t(5);
    sort(str, str+5, t.compareInner(t));
    return 0;
}
