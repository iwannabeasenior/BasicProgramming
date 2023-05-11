#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// #include<stack>
int x=1;
class enumeration
{
private:
    /* data */
public:
   virtual void hello(){
        cout<<"hello";
    }
    enumeration(/* args */);
    ~enumeration();
};
// call when object created
enumeration::enumeration(/* args */)
{
}
enum  season{
    Spring,
    Summer,
    Autumn,
    Winter
};
// overidding
class Derived: public enumeration{
    public : 
     void hello(){
        cout<<"hello Derived";
        enumeration:: hello();
     }
};
// call when scope closed
enumeration::~enumeration()
{
}

using namespace std;
int main(){
//    std :: stack <int > st;
    int x=2;
    cout<<::x;
    season a;
    :: Spring ;
    Derived ex;
    ex.hello();
    enumeration *e=&ex;
    e->hello();
}