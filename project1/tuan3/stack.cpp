#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
    string query;
    int number;
    while(cin >> query) {
        if (query == "PUSH") {
            cin >> number;
            st.push(number);
        } else if (query == "POP") {
            if (!st.empty()) {
                int numberPop = st.top();
                st.pop();
                cout << numberPop << endl;
                
            } else {
                cout << "NULL" << endl;
            }
        } else {
            break;
        }
    }
}