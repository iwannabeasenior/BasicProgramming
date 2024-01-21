#include<bits/stdc++.h>
using namespace std;
int n;
typedef  pair<int, int> Point;
vector<Point> points;


int orientation(Point p, Point q, Point r) {
    int val = (q.second - p.second) * (r.first - q.first) - 
              (q.first - p.first) * (r.second - q.second); 
  
    if (val == 0) return 0;  // collinear 
    return (val > 0)? 1: 2;
}

vector<Point> findVertextHull() {
    // find most left
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].first < points[l].first) {
            l = i;
        }
    }
    //
    vector<Point> hull;
    int p = l, q;
    

    do {
        hull.push_back(points[p]);
        q = (p+1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);
    return hull;
}
int main() {
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }
    vector<Point> hull = findVertextHull();
    cout << hull.size() << endl;
    for (int i = 0; i < hull.size(); i++) {
        cout << hull[i].first << " " << hull[i].second << endl;
    }
}