#include<bits/stdc++.h>
using namespace std;
class base{
    public:
    base(){
        cout<<"1";
    }
   virtual ~base(){
        cout<<"1'";
    }
    void hello(){
        cout<<"hellobase";
    }
};
class derived : public base{
   public :
    derived (){
        cout<<"2";
    }
    ~derived (){
        cout<<"2'";
    }
    void hello(){cout<<"helloderived";}
    void hello1(){}
    
};
int main(){
    derived *d = new derived(); 
    base *b = d;
    //call hello() in base class not in derived class
    b->hello();

    //delete object->destructor called, first call derived destructor and second call base destructor

    delete b;
    cout<<"thanhdepzai";
    getchar();
    return 0;
}