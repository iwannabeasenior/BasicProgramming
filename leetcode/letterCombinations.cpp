#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        int len = digits.length();
        int a[len];
        for (int i=0; i<len; i++){
            a[i] = stoi(digits.substr(i,1));
        }
        // tao 1 vector vector string    
        vector<string> vs[len];
        // khoi tao cho vs,  
        solution(v, vs, 0);
    }   
    vector<string> solution(vector<string>& v, vector<string> vs[],int x){
       for (int i=0; i<3; i++){
            vs[x][i] 
       } 
    }
    
};

int main(){

}