#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class A{
        public :
        int u;
    }
typedef struct Node
{   
    int a;
    Node(){
        a=10;
    }
    Node(int x){
        a=x;
    }
    void hello(){
        std::cout << "/* message */" << std::endl;
    }
    bool operator <(Node &x){
        if(a<x.a){
            return true;
        }
        else return false;
    }
    A a1;
}Node;

int main(int argc, char const *argv[])

    {
    std:: vector<Node> v;
    Node z;
    Node x; 
    x.a=2;
    Node y;
    Node t(10);
    y.a=1;
    v.push_back(x);
    v.push_back(y);
    std::sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].a;
    }
    cout<<z.a;
    cout<<t.a;
    return 0;
}
