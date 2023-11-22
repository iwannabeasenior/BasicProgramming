#include<bits/stdc++.h>
using namespace std;
unordered_map<string, vector<string>> accountBank;

bool hasTransactionCycle(string firstAccount, string fromAccount, set<string> vistied, int k) {
    if (k == 1) {
        for (string account : accountBank[fromAccount]) {
            if (account == firstAccount) {
                return true;
            }
        }
        return false;
    } else {
        for (string account : accountBank[fromAccount]) {
            if (vistied.find(account) == vistied.end()) {
                vistied.insert(account);
                if (hasTransactionCycle(firstAccount, account, vistied, k-1)) {
                    return true;
                }
                vistied.erase(account);
            } 
        }
        return false;
    }
}

int main() {
    int dem = 0;
    set<string> s;
    int number_transactions = 0;
    int total_money_transaction = 0;
    vector<vector<int>> v(10000);
    
    unordered_map<string, int> total_money_transaction_from_name;
    vector<string> list_sorted_accounts;
    string query, s1;
    int k;
    getline(cin, query);
    while (query != "#") {
        string fromAccount, toAccount;
        int money;
        string timePoint, atm;
        dem++;
        istringstream iss(query);
        iss >> fromAccount >> toAccount >> money >> timePoint >> atm;
        total_money_transaction += money;
        total_money_transaction_from_name[fromAccount] += money;
        s.insert(fromAccount);
        s.insert(toAccount);
        accountBank[fromAccount].push_back(toAccount);
        getline(cin, query);
    }
    cin >> query;
    while(query != "#") {
        if (query == "?number_transactions") cout << dem << endl;
        else if (query == "?total_money_transaction") cout << total_money_transaction << endl;
        else if (query == "?list_sorted_accounts") {
            for (auto i = s.begin(); i != s.end(); i++) {
                cout << *i << " ";
            }
            cout << endl;
        } else if (query == "?total_money_transaction_from") {
            cin >> s1;
            cout << total_money_transaction_from_name[s1] << endl;
        } else {
            cin >> s1 >> k;
            set<string> vistited;
            vistited.insert(s1);
            if (hasTransactionCycle(s1, s1, vistited, k)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }  
        }
        cin >> query;
    }
}