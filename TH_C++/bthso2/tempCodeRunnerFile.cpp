#include<iostream>
#include<bits/stdc++.h>
// Nguyen Trung Thanh-20215482
using namespace std;

int main(){
    
    map<int  , int  > b;
    
    int n, m;

    while (cin >> n && cin >> m){
      b[n] = m;
    }
  
    //phai chuyen map->vector roi dung sort va comparator de sort.
    vector<pair<int,int>> v;
    for(auto &i: b){
        v.push_back(i);
    }
    
    auto cmp = [](const std::pair< int , int >& a, const std::pair< int , int  >& b) {
      if(a.second!=b.second)
        return a.second>b.second;
      else{
        return a.first>b.first;
      }
    };

    sort(v.begin(),v.end(),cmp);
    
    for(auto itr=v.begin();itr!=v.end();itr++){
      cout<<itr->first<<" "<<itr->second<<endl;
    }
}