#include<bits/stdc++.h>
#define INFI (1000000000 + 7)
using namespace std;
string str;
unsigned long long result = 0;
bool flag = true;
void adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word == "") {
            flag = false;
            return;
        } else {
            int number = (stoi(word)) % (INFI);
            result += number;
            result = result % INFI;
        }
    }
}
int main() {
    cin >> str;
    adv_tokenizer(str, '+');
    if (flag) {
        cout << result;
    } else {
        cout << "NOT_CORRECT";
    }
}