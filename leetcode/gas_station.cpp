#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int curr = 0;
        int start = 0;
        for (int i = 0; i < n; i++){
            balance += gas[i] - cost[i];
            if (balance < 0){
                start = i + 1;
                curr += balance;
                balance = 0;
            }
        }
        if (curr + balance >= 0) return start;
        return -1;
    }
};
int main(){

}