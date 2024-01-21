// tính giai thừa  n!
#include<iostream>
#include<stack>
using namespace std;
long tinhGiaiThua(int n){
    stack<int> st;
    while (n != 0){
        st.push(n);
        n--;
    }
    
    long giai_thua = 1;

    while(!st.empty()){
        int x = st.top();
        giai_thua *= x;
        st.pop();
    }
    return giai_thua;
}
int main(){
    cout << tinhGiaiThua(3);
}