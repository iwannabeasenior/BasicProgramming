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
    int timeArray[24][60][60];
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                timeArray[i][j][k] = 0;
            }
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
        int hour = stoi(timePoint.substr(0, 2));
        int minute = stoi(timePoint.substr(3, 2));
        int second = stoi(timePoint.substr(6, 2));
        timeArray[hour][minute][second] += price;
        getline(cin, query);
    }
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
            int startSecond = stoi(s1.substr(6, 2));
            int endHour = stoi(s2.substr(0, 2));
            int endMinute = stoi(s2.substr(3, 2));
            int endSecond = stoi(s2.substr(6, 2));
            int profit = 0;
            if (startHour == endHour) {
                for (int a = startMinute+1; a < endMinute; a++) {
                    for (int b = 0; b < 60; b++) {
                        profit += timeArray[startHour][a][b];
                    }
                }
                for (int b = startSecond; b < 60; b++) {
                    profit += timeArray[startHour][startMinute][b];
                }
                for (int b = 0; b <= endSecond; b++) {
                    profit += timeArray[startHour][endMinute][b];
                }
            }
            else 
            for (int a = startHour; a <= endHour; a++) {
                if (a == startHour) {
                    for (int c = startSecond; c < 60; c++) {
                        profit += timeArray[a][startMinute][c];
                    }
                    for (int b = startMinute+1; b < 60; b++) {
                        for (int c = 0; c < 60; c++) {
                            profit += timeArray[a][b][c];
                        }
                    }
                } else if (a == endHour) {
                    for (int b = 0; b < endMinute; b++) {
                       for (int c = 0; c < 60; c++) {
                        profit += timeArray[a][b][c];
                       }
                    }
                    for (int c = 0; c < endSecond; c++) {
                        profit += timeArray[a][endMinute][c];
                    }
                } else {
                    for (int b = 0; b < 60; b++) {
                        for (int c = 0; c < 60; c++) {
                            profit += timeArray[a][b][c];
                        }
                    }
                }
            }
            cout << profit << endl;
        }
        cin >> query;
    }
}