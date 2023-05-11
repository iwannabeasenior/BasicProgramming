#include<bits/stdc++.h>
using namespace std;
class A{
    private:
        int a;
        int b;
    public:
        A(){};
        A(int a,int b): a(a),b(b) {};
        bool operator < (A&);
        int get_a(){
            return a;
        }
        int get_b(){
            return b;
        }
        void recieve_a(int a){
            A::a=a;
        }
};  
    bool A::operator< (A& aa){
        if(a<=aa.get_a()) return true;
        else return false;
    }
int main(){
    vector<A> v;
    A* ptr=new A[5];
    
    for(int i=0;i<5;i++){
        int t;
        cin>>t;
        ptr[i].recieve_a(t);
        v.push_back(ptr[i]);
    }
    sort(v.begin(),v.end());
    vector<A>:: iterator op=v.begin();
    for (op;op!=v.end();op++)
    {
        cout<<(*op).get_a();
    }
    
}