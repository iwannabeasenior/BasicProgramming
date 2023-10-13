#include<bits/stdc++.h>
using namespace std;
int n, m;
int credit[1000];
int matrix[1000][1000];
int load[1000];
int whereToLoad[1000];
int record = 1000;
int maxLoad() {
    int max = 0;
    for (int i = 1; i <= m; i++) {
        if (load[i] > max) max = load[i];
    }
    return max;
}
bool check(int course, int m) {
    for (int i = 1; i <= n; i++) {
        if (matrix[i][course] == 1) {
            if (whereToLoad[i] != 0) {
                if (whereToLoad[i] >= m) return false;
            }
        }
        if (matrix[course][i] == 1) {
            if (whereToLoad[i] != 0) {
                if (whereToLoad[i] <= m) return false;
            }
        }
    }
    return true;
    
}
void Try (int course) {
    for (int i = 1; i <= m; i++) {
        if (check(course, i)) {
            load[i] += credit[course];
            whereToLoad[course] = i;
            if (course == n) {
                if (maxLoad() < record) {
                    record = maxLoad();
                }
            } else {
                if (maxLoad() < record) {
                    Try(course+1);
                } 
            }
            load[i] -= credit[course];
            whereToLoad[course] = 0;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> credit[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }
    Try(1);
    cout << record;
}