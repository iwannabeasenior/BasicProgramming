#include<bits/stdc++.h>
using namespace std;
#define N 1001
int a, b, c ;
bool visited[N][N];

struct State {
    int x, y;
    int step;
    string nameStep;
    State* stateParent;

    State(int _x, int _y, int _step, string _nameStep, State* stateParent) {
        x = _x;
        y = _y;
        step = _step;
        nameStep = _nameStep;
        stateParent = stateParent;
    }
    State(int _x, int _y, int _step) {
        x = _x;
        y = _y;
        step = _step;
        stateParent = nullptr;
    }
};

vector<State*> getNeighborhood(State* s) {
    vector<State*> ns;
    // build 8 stateParent

    auto s1 = new State (a, s->y, s->step+1, "do nuoc day binh A", s); ns.push_back(s1);
    auto s2 = new State (s->x, b, s->step+1, "do nuoc day binh B", s); ns.push_back(s2);
    auto s3 = new State (0, s->y, s->step+1, "do het nuoc ra khoi binh A", s); ns.push_back(s3);
    auto s4 = new State (s->x, 0, s->step+1, "do nuoc het ra khoi binh B", s); ns.push_back(s4);
    if (s->y + s->x >= a) {
        auto s5 = new State (a, s->y - (a-s->x), s->step+1, "do nuoc tu binh B vao day binh A", s); ns.push_back(s5);
    } else {
        auto s6 = new State (s->x + s->y, 0, s->step+1, "do het nuoc tu binh B vao binh A", s); ns.push_back(s6);
    }
    if (s->x + s->y <= b) {
        auto s7 = new State (0, s->x + s->y, s->step+1, "do het nuoc tu binh A sang binh B", s); ns.push_back(s7);
    } else {
        auto s8 = new State (s->x - (b - s->y), b, s->step+1, "do nuoc tu binh A sang day binh B", s); ns.push_back(s8);
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
    queue<State*> Q;
    auto start = new State (0, 0, 0);
    Q.push(start);
    visited[0][0] = true;

    while (!Q.empty()) {
        State* s = Q.front(); Q.pop();
        vector<State*> neighborhood = getNeighborhood(s);
        for (int i = 0; i <  neighborhood.size(); i++) {
            State* ns = neighborhood[i];
            if (ns->x == c || ns->y == c) { 
                State* trace = ns;
                while(trace->stateParent != nullptr) {
                    cout << trace->nameStep << endl;
                    trace = (trace->stateParent);
                }
                return ns->step;
            }
            if (!visited[ns->x][ns->y]) {
                Q.push(ns); visited[ns->x][ns->y] = true;
            }
        }
    }
    return -1;
       
}
int main() {
    cout << calStep();
}