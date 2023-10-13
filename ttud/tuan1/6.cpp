#include<bits/stdc++.h>
using namespace std;
void simple_tokenizer(string s)
{
    map<string, int> m;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        cout << word << endl;
    }
}
 
// A quick way to split strings separated via any character
// delimiter.
void adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
    }
}
int main() {
    string str ;
    map<string, int> m;
    string word;
    while (cin >> word) {
        if (m.find(word) != m.end()){
            m[word]++;
        }else m[word] = 1;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    // thao tac voi file 
    // while (!feof(stdin)) {
        // string str = fgetc(stdin);
    //     cout << str << endl;
    // }
    
 
}