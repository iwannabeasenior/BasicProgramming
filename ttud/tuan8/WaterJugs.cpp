#include<bits/stdc++.h>
using namespace std;
#define N 1001
int a, b,c ;
bool visited[N][N];

struct State {
    int x, y;
    int step;
    State(int _x, int _y, int _step) {
        x = _x;
        y = _y;
        step = _step;
    }
    State* state;
};

vector<State> getNeighborhood(State s) {
    vector<State> ns;
    // build 8 state

    State s1(a, s.y, s.step+1); ns.push_back(s1);
    State s2(s.x, b, s.step+1); ns.push_back(s2);
    State s3(0, s.y, s.step+1); ns.push_back(s3);
    State s4(s.x, 0, s.step+1); ns.push_back(s4);
    if (s.y + s.x >= a) {
        State s5(a, s.y - (a-s.x), s.step+1); ns.push_back(s5);
    } else {
        State s6(s.x + s.y, 0, s.step+1); ns.push_back(s6);
    }
    if (s.x + s.y <= b) {
        State s7(0, s.x + s.y, s.step+1); ns.push_back(s7);
    } else {
        State s8(s.x - (b - s.y), b, s.step+1); ns.push_back(s8);
    }
    
    return ns;
}
int calStep() {
    
    cin >> a >> b >> c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    queue<State> Q;
    State start(0, 0, 0);
    Q.push(start);
    visited[0][0] = true;

    while (!Q.empty()) {
        State s = Q.front(); Q.pop();
        vector<State> neighborhood = getNeighborhood(s);
        for (int i = 0; i <  neighborhood.size(); i++) {
            State ns = neighborhood[i];
            if (ns.x == c || ns.y == c) return ns.step;
            if (!visited[ns.x][ns.y]) {
                Q.push(ns); visited[ns.x][ns.y] = true;
            }
        }
    }
    return -1;
    
    
}
int main() {
    cout << calStep();
}