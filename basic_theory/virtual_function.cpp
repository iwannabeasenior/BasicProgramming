// C++ program to illustrate
// concept of Virtual Functions
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class base {
public:
    virtual void print() { cout << "print base class\n"; }
 
    void show() { cout << "show base class\n"; }
};
 
class derived : public base {
public:
    void print() { cout << "print derived class\n"; }
 
    void show() { cout << "show derived class\n"; }

    void nothing() { cout<<"nothing\n"; }
};

int main()
{

    base* bptr;
    derived d;
    bptr = &d;
    
    // Virtual function, binded at runtime
    bptr->print();
 
    // Non-virtual function, binded at compile time
    bptr->show();
    
   // bptr->nothing(); : error: 'class base' has no member named 'nothing'
    return 0;
    
}