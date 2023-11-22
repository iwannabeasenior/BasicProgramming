#include<bits/stdc++.h>
using namespace std;
vector<string> Etract(const string& query) {
    stringstream ss(query);
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

int getTime(string time) {
    return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

bool comp(pair<int, int> map1, pair<int, int> map2) {
    return map1.first - map2.first < 0;
}

int main() {

    int dem = 0;
    string query;
    string s1, s2;
    int timeArray[24][60];
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            timeArray[i][j] = 0;
        }
    }
    getline(cin, query);
    int totalNumberOrder = 0;
    int totalRevenue = 0;
    unordered_map<string, int> revenueOfShop;
    map<pair<string, string>, int> CustomerShop; 
    vector<pair<int, int>> time;

    while (query != "#") {
        totalNumberOrder++;
        string CustomerID;
        string ProductID;
        int price;
        string shopID;
        string timePoint;
        istringstream iss(query);
        iss >> CustomerID >> ProductID >> price >> shopID >> timePoint;
        totalRevenue += price;
        revenueOfShop[shopID] += price;
        CustomerShop[{CustomerID, shopID}] += price;
        int start = stoi(timePoint.substr(0, 2));
        int end = stoi(timePoint.substr(3, 2));
        timeArray[start][end] = price;
        getline(cin, query);
    }
    
    sort(time.begin(), time.end(), comp);
    cin >> query;

    while (query != "#") {
        if (query == "?total_number_orders") {
            cout << totalNumberOrder << endl;
        } else if (query == "?total_revenue") {
            cout << totalRevenue << endl;
        } else if (query == "?revenue_of_shop") {
            cin >> s1;
            cout << revenueOfShop[s1] << endl;
        } else if (query == "?total_consume_of_customer_shop") {
            cin >> s1 >> s2;
            cout << CustomerShop[{s1, s2}] << endl;
        } else {
            cin >> s1 >> s2;
            int startHour = stoi(s1.substr(0, 2));
            int startMinute = stoi(s1.substr(3, 2));
            int endHour = stoi(s2.substr(0, 2));
            int ednMinute = stoi(s2.substr(3, 2));
            int profit = 0;
            for (int a = startHour; a <= endHour; a++) {
                if (a == startHour) {
                    for (int b = startMinute; b < 60; b++) {
                        profit += timeArray[a][b];
                    }
                } else if (a == endHour) {
                    for (int b = 0; b <= ednMinute; b++) {
                        profit += timeArray[a][b];
                    }
                } else {
                    for (int b = 0; b < 60; b++) {
                        profit += timeArray[a][b];
                    }
                }
            }
            cout << profit << endl;
        }
        cin >> query;
    }
}