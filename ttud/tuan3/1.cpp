#include<bits/stdc++.h>
using namespace std;
int n, m; 
vector<int> course[1000];
bool conflict[1000][1000];
vector<int> load[1000];
int record = 1000;
int maxLoad() {
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (load[i].size() > max) max = load[i].size();
    }
    return max;
}
bool check(int k, int v) {
    if (conflict[k][v]) {
        return false;
    } 
    return true;
    
}
bool check2(int i, int x) {
    for (int j = 0; j < load[i].size(); j++) {
            if (check(x, load[i][j])) {
            } else return false;
    }
    return true;
}

void Try(int x)  {
    for (int i = 0; i < course[x].size(); i++) {
        if(check2(course[x][i], x)) {
            load[course[x][i]].push_back(x);
            // if x == n -> solution
            if (x == m) {
                if (maxLoad() < record) record = maxLoad();
            } else {
                if (maxLoad() < record) {
                    Try(x+1);
                }
            }
            load[course[x][i]].pop_back();
            // if max load < kiluc -> Try(x+1)
            // back state
        }
    }
}
int main() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            conflict[i][j] = false;
        }
    }

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int t; cin >> t;
            course[t].push_back(i);
        }
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = true;
        conflict[b][a] = true;
    }
    Try(1);
    cout << record;
    // try tu 1 -> m
}