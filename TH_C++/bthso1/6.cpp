#include<stdio.h>

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    while(l<r){
        tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
        l++;
        r--;
        }
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    while(l<r){
        tmp=*(arr+l);
        *(arr+l)=*(arr+r);
        *(arr+r)=tmp;
        l++;
        r--;
    }
    
}
int main(){
    int arr[]={1,2,3,4};
    reversearray(arr,4);
    for(int i=0;i<4;i++){
        printf("%d",arr[i]);
    }
}