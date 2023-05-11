#include<iostream>
using namespace std;
class B;
class A{
    private:
        int a;
        void hello(){
          a=1;
          cout<<"hello world";  
        }
        friend class B;
};
class B{
    public :
        void friend1(){
            A a;
            a.hello();
        }
};
int main(){
    B b;
    b.friend1();
}