#include<bits/stdc++.h>
using namespace std;
unordered_map<string, tuple<string, string, string>> ancestor;
unordered_map<string, int> numberOfDate; 
unordered_map<string, int> visited;
//0000001 1920-08-10 0000000 0000000 Y 00002
void mostAliveAncester() {
    
}
bool checkCanContinue() {
    for (auto it = visited.begin(); it != visited.end(); it++) {
        if (it->second == 0) {
            return true;
        }
    }
    return false;
}
int maxUnrelatedPeople(string FirstId, string id, int count, set<string> include) {
    visited[FirstId] = 1;
    if (!checkCanContinue()) {
        return count;
    }
    for (auto it = ancestor.begin(); it != ancestor.end(); it++) {
        if (visited[it->first] == 0) {
            count++;
            visited[it->first] = 1;
            maxUnrelatedPeople(FirstId, it->first, count, include);
        } 
    }

}

int main() {
    string query;
    int number_people = 0;
    
    
    getline(cin, query);
    while (query != "*") {
        string id, date, idFather, idMother, isAlive, code;
        number_people++;
        stringstream ss(query);
        ss >> id >> date >> idFather >> idMother >> isAlive >> code;
        numberOfDate[date]++;
        ancestor[id] = {idFather, idMother, isAlive};
        getline(cin, query);
    }

    getline(cin, query);
    string a, b;

    while (query != "***") {
        if (query == "NUMBER_PEOPLE") {
            cout << number_people << endl;
        } else if (query == "NUMBER_PEOPLE_BORN_AT") {
            cin >> a;
            cout << numberOfDate[a] << endl;
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            cin >> a;
            
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            cin >> a >> b;
        } else {

        }
    }
}