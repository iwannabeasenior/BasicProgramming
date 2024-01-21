#include<bits/stdc++.h>
using namespace std;
class A{

    private: int t;
    public:

    // default constructor
    A(){
        cout<<"A is constructor";
    }

    //  Parameterized Constructor
    A(int a){
        t=a;
    }

    // copy constructor
    A(A &a){
        t=a.t;
    }
};
int main(){
    A a;
    A a1(2);
    
    // call copy constructor
    A a2=a;
}