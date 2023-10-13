#include<bits/stdc++.h>
using namespace std;
bool checkFormat(string ymd) {
    int len = ymd.length();
    if (len != 10) return false;
    else {
        for (int i = 0; i < 10; i++) {
            if (i == 4 || i == 7) {
                if (ymd[i] != '-') return false;
            } else {
                if (!isdigit(ymd[i])) {
                    return false;
                }
            }
        }
        return true;
    }
}
int main() {
    string ymd;
    getline(cin, ymd);
    if (checkFormat(ymd)) {
        int month = stoi(ymd.substr(5, 2));
        int date = stoi(ymd.substr(8, 2));
        if (month <= 12 && month >= 1 && date <= 31 && date >= 1) {
            cout << ymd.substr(0, 4) << " " << month << " " << date;
        } else {
            cout << "INCORRECT";
        } 
    } else {
        cout << "INCORRECT";
    }
}