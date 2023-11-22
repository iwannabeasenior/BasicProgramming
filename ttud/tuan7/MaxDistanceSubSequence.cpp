// divide and conquer
#include<bits/stdc++.h>
using namespace std;
int n,c;
bool check(int d, int a[]) {
    int last = 1;
    int cnt = 1;
    while (last < n) {
        int j = last + 1;
        while (j <= n) {
            if (a[j] - a[last] >= d) {
                cnt++;
                last = j;
                break;
            }
            else {
                j++;
            }  
        }
        if (cnt == c) return true;
        if (j == n + 1) return false;
    }
    return false;
}
int maxDistance(int start, int end, int a[]) {
    if (start == end) return start;
    if (start+1 == end) {
        if (check(end, a)) {
            return end;
        } else return start;
    } 
    int mid = (end+start)/2;
    if (check(mid, a)) {
        return maxDistance(mid, end, a);
    } else {
        return maxDistance(start, mid-1, a);
    }
}
int main() {    
    int t; cin >> t;
    while (t > 0) {
        cin >> n >> c;
        int a[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);

        cout << maxDistance(0, a[n]-a[1], a) << endl;
        t--;
    }
}