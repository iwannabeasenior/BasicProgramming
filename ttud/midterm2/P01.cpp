#include<bits/stdc++.h>
#define INFI (1000000000 + 7)
using namespace std;
vector<string> multiply;
vector<unsigned long long> multiplyResult;
bool flag1 = true;
unsigned long long result = 0;
void adv_tokenizer1(string s, char del)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word == "") {
            flag1 = false;
            return;
        } else {
            multiply.push_back(word);
        }
    }
}
int adv_tokenizer2(string s, char del)
{
    unsigned long long resultOfMultiply = 1;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        if (word == "") {
            return 0;
        } else {
            resultOfMultiply *= (stoi(word) % INFI);
            resultOfMultiply %= INFI;
        }
    }
    return resultOfMultiply % INFI;
}
int main() {
    string str; cin >> str;
    adv_tokenizer1(str, '+');
    if (flag1) {
        bool flag = true;
        for (auto s : multiply) {
            unsigned long long t = adv_tokenizer2(s, '*');
            if (t == 0) {
                cout << "NOT_CORRECT";
                flag = false;
                break;
            } else {
                result += t;
                result = result % INFI;
            }
        }
        if (flag) {
            cout << result;
        }
    } else {
        cout << "NOT_CORRECT";
    }
}