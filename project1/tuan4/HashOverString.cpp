#include<vector>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
void hashCode(vector<string> str, int m) {
    for (int i = 0; i < str.size(); i++) {
        long long result = 0;
        int len = str[i].length();
        for (int j = 0; j < len; j++) {
            long long sum = str[i][j] % m;
            // long long sum = (str[i][j] * ((long long)pow(256, len-j-1) % m)) % m;
            for (int k = 1; k <= len-j-1; k++) {
                sum *= 256;
                sum %= m;
            }
            result += sum;
            result = result % m;
        }
        cout << result << endl;
    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    hashCode(str, m);
}