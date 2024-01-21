
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int P=1e6+3;

struct HashTable{
    vector<pair<int , int>> h[P];
    public :
        void insert(int key,int value){
            int index=hashfunc(key);
            for(auto p: h[index]){
                if(p.first==key){
                    return ;
                }
            }
            h[index].emplace_back(key,value);
        }
        int find(int key){
            int index=hashfunc(key);
            for(auto p: h[index]){
                if(p.first==key){
                    return p.second;
                }
            }
            return 0;
        }
    private: 
        int hashfunc(int key){
            return key%P;
        }
};
int main(){
    HashTable ht;
    ht.insert(1,2);
    ht.insert(2,3);
    cout<<ht.find(1);
}