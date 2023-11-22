// gready
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> jobs;
bool comp(const pair<int, int>&a, const pair<int, int>&b) {
    return a.second > b.second;
}
int main() {
    int n; 
    cin >> n;
    int a, b;
    int profit = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        jobs.push_back({a,b});
    }
    sort(jobs.begin(), jobs.end(), comp);
    bool day[100000];
    // int time = 1;
    memset(day, false, sizeof(day));
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].first - 1; j >= 0; j--) {
            if (!day[j]) {
                day[j] = true;
                profit += jobs[i].second;
                break;
            }
        }
    }
    cout << profit;
}