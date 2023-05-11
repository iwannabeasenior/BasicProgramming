#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
struct Workshop{
    int start_time;
    int duration;
    int end_time=start_time+duration;
};

struct Available_Workshops{
    int n;
    Workshop* ptr1=new Workshop[n];
};
Available_Workshops* aw=new Available_Workshops();

Available_Workshops* initialize (int start_time[], int duration[], int n){
    // Available_Workshops* aw=new Available_Workshops();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(start_time[j]>start_time[j+1]){
                swap(&start_time[j],&start_time[j+1]);
                swap(&duration[j],&duration[j+1]);
            }
        }
    }
    aw->n=n;
    for(int i=0;i<n;i++){
        aw->ptr1[i].start_time=start_time[i];
        aw->ptr1[i].duration=duration[i];
        // aw->ptr[i].end_time=end_time[i];
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int t=ptr->n;
    int count=1;
    int max=0;
    for(int k=0;k<t;k++){
        count=0;
        for(int i=k;i<t;i++){
        for(int j=i+1;j<5;j++){
            if(ptr->ptr1[i].end_time<=ptr->ptr1[j].start_time){
                count++;
                if(count>max) max=count;
                i=j;
                break;
            }
        }
    }
    }
    return max;
}
int main(){


}