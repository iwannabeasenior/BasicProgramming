#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream> 

using namespace std;

bool hasTransactionCycle(const string firstAccount, const vector<string>& transactions, const string& account, int k, set<string>& visited) {
    if (k == 1) {
        for (const string& transaction : transactions) {
            string fromAccount, toAccount;
            int money;
            string timePoint, atm;
            istringstream iss(transaction);
            iss >> fromAccount >> toAccount >> money >> timePoint >> atm;

            if (fromAccount == account && visited.find(toAccount) == visited.end() && toAccount == firstAccount) {
                return true;
            }
        }
        return false;
    }

    else {
        for (const string& transaction : transactions) {
            string fromAccount, toAccount;
            int money;
            string timePoint, atm;
            istringstream iss(transaction);
            iss >> fromAccount >> toAccount >> money >> timePoint >> atm;

            if (fromAccount == account && visited.find(toAccount) == visited.end()) {
                visited.insert(toAccount);
                if (hasTransactionCycle(firstAccount, transactions, toAccount, k - 1, visited)) {
                    return true;
                }
                visited.erase(toAccount);
            }
        }
    }

    return false;
}

int main() {
    vector<string> transactions;

    while (true) {
        string line;
        getline(cin, line);
        if (line == "#") {
            break;
        }
        transactions.push_back(line);
    }

    while (true) {
        string line;
        getline(cin, line);
        if (line == "#") {
            break;
        }

        if (line == "?number_transactions") {
            cout << transactions.size() << endl;
        } else if (line == "?total_money_transaction") {
            int totalMoney = 0;
            for (const string& transaction : transactions) {
                string fromAccount, toAccount;
                int money;
                string timePoint, atm;
                istringstream iss(transaction);
                iss >> fromAccount >> toAccount >> money >> timePoint >> atm;
                totalMoney += money;
            }
            cout << totalMoney << endl;
        } else if (line == "?list_sorted_accounts") {
            set<string> allAccounts;
            for (const string& transaction : transactions) {
                string fromAccount, toAccount;
                int money;
                string timePoint, atm;
                istringstream iss(transaction);
                iss >> fromAccount >> toAccount >> money >> timePoint >> atm;
                allAccounts.insert(fromAccount);
                allAccounts.insert(toAccount);
            }
            for (const string& account : allAccounts) {
                cout << account << " ";
            }
            cout << endl;
        } else if (line.find("?total_money_transaction_from ") == 0) {
            string account = line.substr(30);
            int totalMoney = 0;
            for (const string& transaction : transactions) {
                string fromAccount, toAccount;
                int money;
                string timePoint, atm;
                istringstream iss(transaction);
                iss >> fromAccount >> toAccount >> money >> timePoint >> atm;
                if (fromAccount == account) {
                    totalMoney += money;
                }
            }
            cout << totalMoney << endl;
        } else if (line.find("?inspect_cycle ") == 0) {
            istringstream iss(line);
            string x;
            iss >> x;
            string account;
            int k;
            iss >> account;
            iss >> k;
            set<string> visited;
            visited.insert(account);
            if (hasTransactionCycle(account , transactions, account, k, visited)) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}