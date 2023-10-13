#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len = arr.size();
        int first = 0;
        int second = len-1;
        while (first <= second){
            int mid = (first+second)/2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if (arr[mid] < arr[mid + 1]) {
                first = mid + 1;
            }
            else {
                second = mid;
            }
        }
    }
};

// c2 : toi uu
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int first = 0;
        int second = arr.size() - 1;
        int mid = (first + second)/2; 
        while (first < second){
            if (arr[mid] < arr[mid + 1]) first = mid + 1; // nếu nằm ở sườn bên kia thì first = mid + 1; vì mid chắc chắn ko phải đỉnh
            else second = mid; // nếu nằm ở sườn bên phải thì second = mid vì mid có thể là đỉnh
            mid = (first + second)/2;
        }
        return mid; // kết quả cuối cùng sẽ là đỉnh khi first = second;
    }
};