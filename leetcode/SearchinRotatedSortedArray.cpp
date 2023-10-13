#include<bits/stdc++.h>
using namespace std;
// y tuong : tìm được pivot là điểm chia dãy thành 2 dãy tăng, rồi xem target thuộc dãy nào rồi dùng binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int first = 0;
        int second = len-1;
        int mid = (first + second)/2;
        while (first < second) {
            if (nums[mid] > nums[len-1]){
                first = mid + 1;
            }
            else {
                second = mid;
            }
            mid = (first+second)/2;
        }
        if (target == nums[mid]) return mid;
        if (target <= nums[len-1]){
            first = mid;
            second = len-1;
        }
        else{
            first = 0;
            second = mid-1;
        }
        int m = (first+second)/2;
        while (first <= second){
            if (target == nums[m]) return m;
            else if (target > nums[m]) {
                first = m + 1;
            }
            else { 
                second = m - 1;
            }
            m = (second+first)/2;
        }
        return -1;
    }

};


// c2: dung realmid (y tuong giong c1 nhung toi uu hon)
class Solution {
public:
    int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};

