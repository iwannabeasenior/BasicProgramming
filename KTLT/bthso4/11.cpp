#include<bits/stdc++.h>
using namespace std;
//Nguyen Trung Thanh - 20215482
int n, s;
int min(int a, int b){
    return (a < b) ? a : b;
}
int soGiac(priority_queue<pair<int,int>> &v){

    int soGiac = 0;
    int i = 1;
    
    while (s > 0) {
        pair<int, int> p = v.top();
        v.pop();
        int heso = p.second / p.first;
        // s < heso -> khong du linh nua
        int updateHeso = min(heso,s);
        // cập nhật số lính
        s -= updateHeso;
        // tạo ra 1 cửa thành mới với ai = ki 
        int newFirst = p.second - updateHeso * p.first;
        
        v.push(make_pair(newFirst, newFirst));
    }

    while (!v.empty()){
        pair<int, int> p = v.top();
        soGiac += p.second;
        v.pop();
    }
    return soGiac;
}


int main(){
    
    cin >> n >> s;
    int a[n + 1];
    int k[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> k[i];
    }
    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; i++){
        pq.push(make_pair(k[i], a[i]));
    }
    cout << soGiac(pq);
}