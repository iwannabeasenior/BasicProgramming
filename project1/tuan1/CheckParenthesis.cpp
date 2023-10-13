#include<bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    stack<int> st;
    int number;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            st.push(str[i]);
        }
        else {
            if (st.empty()) {
                cout << 0;
                return 0;
            } else {
                if (str[i] == ')') {
                    number = st.top();
                    if (number == '(') {
                        st.pop();
                    } else {
                        cout << 0;
                        return 0;
                    }
                } else if (str[i] == ']') {
                    number = st.top();
                    if (number == '[') {
                        st.pop();
                    } else {
                        cout << 0;
                        return 0;
                    }
                } else if (str[i] == '}') {
                    number = st.top();
                    if (number == '{') {
                        st.pop();
                    } else {
                        cout << 0;
                        return 0;
                    }
                }

            }
        }
    }
    if (st.empty()) {
        cout << 1;
    } else cout << 0;

}