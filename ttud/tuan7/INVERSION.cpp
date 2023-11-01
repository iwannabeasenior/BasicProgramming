#include<bits/stdc++.h>
#define MAX (int)(1e9 + 7)
using namespace std;
unsigned long long  dem = 0;
void merge(int a[], int l, int m, int r){
    int lFirst = l;
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0, j = 0;
    bool flag = false;

    while (i < x.size() && j < y.size()){
        if (x[i] <= y[j]){
            a[l] = x[i]; l++; i++; 
            dem += j;
            flag = false;
        }
        else{
            a[l] = y[j]; l++; j++;
        }
    }

    while (i < x.size()){
        a[l] = x[i]; l++; i++; 
        dem += j;
        dem % MAX;
    }

    while (j < y.size()){
        a[l] = y[j]; l++; j++;
    }     
}

void mergeSort(int a[], int l, int r){

    if (l < r){
        int mid = l + (r-l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int a[1000000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
   
    cout << dem % MAX;
}