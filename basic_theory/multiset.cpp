#include<bits/stdc++.h>
using namespace std;
int main(){
    //multiset same set, but can have same value .in order(both)
    multiset<int > ms;
    ms.insert(10);
    ms.insert(9);
    ms.insert(12);
    ms.insert(8);
    ms.insert(8);
    for(int i: ms){
        cout<<i;
    }
    cout<<""<<endl;
    set<int> s;
    s.insert(10);
    s.insert(9);
    s.insert(12);
    s.insert(8);
    s.insert(10);
    for(int i:s){
        cout<<i;
    }
}