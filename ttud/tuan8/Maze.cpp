#include<bits/stdc++.h>
using namespace std;
int n, m, row, column;
int maze[1001][1001];
bool visited[1001][1001];
struct State {
    int r, c;
    int step;
    State(int _r, int _c, int _step) {
        r = _r;
        c = _c;
        step = _step;
    }
};
vector<State> getWay(State s) {
    vector<State> state;
    if (!maze[s.r + 1][s.c]) {
        State s1(s.r + 1, s.c, s.step+1);
        state.push_back(s1);
    } 
    if (!maze[s.r-1][s.c]) {
        State s2(s.r-1, s.c, s.step+1);
        state.push_back(s2);
    } 
    if (!maze[s.r][s.c + 1]) {
        State s3(s.r, s.c+1, s.step+1);
        state.push_back(s3);
    }
    if (!maze[s.r][s.c-1]) {
        State s4(s.r, s.c-1, s.step+1);
        state.push_back(s4);
    }
    return state;
}
int main() {
    
    cin >> n >> m >> row >> column;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = false;
        }
    }
    visited[row][column] = true;
    queue<State> q;
    q.push(State(row, column, 0));
    while (!q.empty()) {
        State top = q.front(); q.pop();
        vector<State> way = getWay(top);
        for (int i = 0; i < way.size(); i++) {
            if (way[i].r == n || way[i].c == m || way[i].c == 1 || way[i].r == 1) {
                    cout << way[i].step + 1;
                    return 0;
            }
            if (!visited[way[i].r][way[i].c]) {
                    q.push(way[i]);
                    visited[way[i].r][way[i].c] = true;
            }
        }
    }
    cout << -1; return 0;
}