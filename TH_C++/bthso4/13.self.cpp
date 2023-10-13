#include<bits/stdc++.h>
using namespace std;

int soLuong(string s){
    int len = s.length();
    int count = 0;
    vector<int> count_sub(len+1);
    for (int i=0; i<=len; i++){
        count_sub[i] = 0;
    }
    if (s[0] == '0') {
        count_sub[1] = 1;
    }
    else {
        count_sub[1] = -1;
    }    
    for (int i=2; i<=len; i++){
        if (s[i-1] == '0')
        count_sub[i] = count_sub[i-1] + 1;
        else count_sub[i] = count_sub[i-1] - 1;
    }
    for (int i=2; i<=len; i++){
        for (int j=0; j<i-1; j++){
            if (count_sub[i] == count_sub[j]) count++;
        }
    }
    return count;
}

int main(){
    
    #ifndef ONLINE_JUDGE1
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    cout << soLuong(s);
}