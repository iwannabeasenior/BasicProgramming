#include<bits/stdc++.h>
using namespace std;
template <class T>
class A{
  public :T a;
  public :
  // constructor
  A(T n): a(n) {}
  
  //function hello
  T hello(T t){
    return t;
  }  
};
// default parameter
template<class T,class U ,class V=char>
class B{
    public :
    T t;
    U u;
    V v;
};
int main(){
    A<string> b("hello");
    cout<<b.hello("thanh dep trai");
    cout<<b.a;
    B<string, int> b;
    B<string ,int ,bool> b1;
}