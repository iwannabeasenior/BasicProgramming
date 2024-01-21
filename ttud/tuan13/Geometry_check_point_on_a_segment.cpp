#include<bits/stdc++.h>
using namespace std;
int n;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {};
};

double distance(Point a, Point b) {
   return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
int main() {
    cin >> n;
    int x1, y1, x2, y2, x3, y3;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point A = Point(x1, y1);
        Point B = Point(x2, y2);
        Point C = Point(x3, y3);
        bool thangHang = false;
        int a1 = x1-x2, a2 = y1-y2, b1 = x1-x3, b2 = y1-y3;
        double c1 = double(a2) / (double)a1;
        double c2 = double (b2) / (double)b1;
        cout << c1 << c2;
        if ((a1 == 0 && b1 == 0) || (a2==0 && b2==0)) {
            thangHang = true;
        } else if ((a1 == 0 && a2 == 0) || (b1 == 0 && b2 == 0)) {
            thangHang = true;
        } else if (1.0 * a2/a1 == 1.0 * b2/b1) {
            thangHang = true;
        }
        
        if (thangHang && (distance(B, A) + distance(A, C) == distance(B, C))) {
            cout << 1 << endl;
        } else {
      
            cout << 0 << endl;
        }
        cout << distance(B, A) + distance(A, C)  << " " << distance(B, C) ;
       
    }

}