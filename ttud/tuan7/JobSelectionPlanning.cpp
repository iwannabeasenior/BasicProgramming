#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a, const pair<int, int> &b) {
    if (a.first == 0) return 1;
    else if (b.first == 0) return -1;
    return a.second/a.first > b.second/b.first;
}
int main() {
    int n; cin >> n;
    int a, b;
    deque<pair<int, int>> jobs;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        jobs.push_back({a, b});
    }
    int profit = 0;
    sort(jobs.begin(), jobs.end(), comp);
    while(!jobs.empty()) {
        profit += jobs[0].second;
        jobs.pop_front();
        for (auto &p : jobs) {
            p.first -= 1;
        }
        sort(jobs.begin(), jobs.end(), comp);
        while (!jobs.empty()) {
            if (jobs[0].first == 0) {
                jobs.pop_front();
            } else {
                break;
            }
        }
    }
    cout << profit;
}