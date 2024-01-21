#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> N(1000);
bool visitedA[1000] = {false};
bool visitedB[1000] = {false};
bool matched[1000] = {false};
int M[1000];
bool augmenting(int u);
void bipartiteMaximumMatching() {
    while (true) {
        int willContinue = 0;
        for (int i = 1; i <= n; i++) {
            visitedA[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            visitedB[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            if (!visitedA[i] && !matched[i]) {
                if (augmenting(i)) willContinue++;
            }
        }
        if (willContinue == 0) break;
    }
}

bool augmenting(int u) {
    cout << 1;
    visitedA[u] = true;
    for (auto v : N[u]) {
        if (!matched[v]) {
            M[v] = u;
            return true;
        }
        if (!visitedB[v]) {
            visitedB[v] = true;
            if (!visitedA[M[v]] && augmenting(M[v])) {
                M[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 1000; i++) {
        M[i] = -1;
    }
    cin >> n >> m;    
    int k, value;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> value;
            N[i].push_back(value);
        }
    }
    bipartiteMaximumMatching();
    int dem  = 0;
    for (int i = 0; i < 1000; i++) {
        if (M[i] != -1) dem++; 
    }
    cout << dem;
}