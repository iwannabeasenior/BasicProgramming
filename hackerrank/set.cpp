#include<bits/stdc++.h>
using namespace std;
int main(){
    
    set<int> s;
    int q;
    cin>>q;
    while (q--)
    {
        int x,y;
        cin>>y>>x;
    
        if(y==1){
            s.insert(x);
        }
        else if(y==2)
        {
            set<int> :: iterator op=s.find(x) ;
            if(op!=s.end()){
                s.erase(op);
            }
        }
        else if(y==3)
        {
            set<int> :: iterator op=s.find(x) ;
            if(op==s.end()){
                cout<<"No"<<"\n";
            }
            else cout<<"Yes"<<"\n";

        }
        
    }
    
}