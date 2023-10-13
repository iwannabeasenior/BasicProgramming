//C++ 
#include <bits/stdc++.h> 
using namespace std;
int main() { 
    int a, b, c;
    cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if (delta < 0) {
        cout << "NO SOLUTION";
    } else if (delta == 0) {
        printf("%.2lf", -(double)b/(2*a));
    } else {
        double canDelta = sqrt(delta);
        double x1 = (-b - canDelta) / (2*a);
        double x2 = (-b + canDelta) / (2*a);
        printf("%.2lf %.2lf", x1, x2);
    }
}