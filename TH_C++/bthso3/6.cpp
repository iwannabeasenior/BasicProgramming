#include <iostream>
using namespace std;
// Nguyễn Trung Thành - 20215482
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    int temp;
    while(b != 0){
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}