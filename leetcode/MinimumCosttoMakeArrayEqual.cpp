#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ll = 0;
        double a = 0;
                
        long long b = 0;
        for (int i : cost){
            b += i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            a += nums[i]*((float)cost[i]/b);
        }
        
        int  r_avg = round(a);
        
        for (int i = 0; i < nums.size(); i++)
        {
            ll += (long long)abs(r_avg - nums[i]) * cost[i];
        }
        return ll;
    }
};
int main(){
    
}