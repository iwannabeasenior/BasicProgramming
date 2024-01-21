#include<stdio.h>
#define MAX 100 
typedef struct SinhVien{
    int masv;
    char tensv[100];
    char lop[100];
    double diemtk;
    char hanhkiem[100];
}sv;
typedef struct DSKe{
    sv A[MAX];
    int n;
}DSke;
void KhoiTao(DSKe &ds){
    ds.n=0;
}
int KiemTraRong(DSKe ds){
    if(ds.n==0){
        return 1;
    }
    return 0;
}
int KiemTraDay(DSKe ds){
    if(ds.n==MAX){
        return 1;
    }
    return 0;
}
void Nhap(DSKe &ds){
    for(int i=0;i<ds.n;i++)
    {
        scanf("%d",&ds.A[i].masv); fflush(stdin);
        gets(ds.A[i].tensv);fflush(stdin);
        gets(ds.A[i].lop);fflush(stdin);
        scanf("%ld",&ds.A[i].diemtk);fflush(stdin);
        gets(ds.A[i].hanhkiem);fflush(stdin);

    }
}
void DuyetDS(DSKe ds){

}
void TimKiem(DSKe ds){

}
void Xoaptcuoi(DSKe ds){
    
}
int main(){
    DSKe ds;
    

}