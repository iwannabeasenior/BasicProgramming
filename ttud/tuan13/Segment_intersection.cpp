#include<bits/stdc++.h>
using namespace std;
int n;
struct Segment {
    int xA, yA, xB, yB;
    Segment(int _xA, int _yA, int _xB, int _yB) : xA(_xA) , yA(_yA), xB(_xB), yB(_yB) {};
};
vector<Segment> segments;
void input() {
    cin >> n;
    int xA, yA, xB, yB;
    for (int i = 1; i <= n; i++) {
        cin >> xA >> yA >> xB >> yB;
        segments.push_back(Segment(xA, yA, xB, yB));
    }
}
int countSegmentIntersection() {
    int count = 0;
    
    return count;
}
int main() {
    input();
}