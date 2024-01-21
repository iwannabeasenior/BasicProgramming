#include<stdio.h>
#define MAX 100
typedef struct  DSKe{
    int A[MAX];
    int n;
}DSKe;
void KhoiTao(DSKe &ds){
    ds.n==0;
}
int  KiemTraRong(DSKe ds){
    if(ds.n==0) 
    return 1;
    return 0;
}
int KiemTraDay(DSKe ds){
    if(ds.n==MAX){
        return 1;
    }
    return 0;
}
//them phan tu vao dau danh sach mang
void ChenDau(DSKe &ds,int x){
    if(KiemTraDay(ds)==1){
        return ;
    }
    if(ds.n>0){
        for(int i=ds.n;i>=1;i--){
            ds.A[i]=ds.A[i-1];
        }
    }
    ds.A[0]=x;
    ds.n=ds.n+1;
}
//them phan tu vao cuoi danh sach mang
void ChenCuoi(DSKe &ds,int x){
    if(KiemTraDay(ds)==1) return ;
        ds.A[ds.n]=x;
        ds.n=ds.n+1;
}
//them phan tu vao giua danh sach mang
void ChenGiua(DSKe &ds,int p,int x){
   
    if(p==0){
        ChenDau(ds,x);
    }
    else if(p==ds.n){
        ChenCuoi(ds,x);
    }
    else{
         if(KiemTraDay(ds)==1) return ;
         for(int i=ds.n;i>p;i--){
            ds.A[i]=ds.A[i-1];
         }    
    }
    ds.A[p]=x;
    ds.n+=1;
}
// duyet danh sach mang
void DuyetDS(DSKe ds){
    int p=0;
    while(p<ds.n){
        printf("%d ",ds.A[p]);
        p++;
    }
}
//xoa phan tu o vi tri p
void XoaPhanTu(DSKe &ds,int p){
    if(ds.n<=0||p<0||p>=ds.n){
        printf("Danh sach khong chua phan tu");
        return ;
    }
    for(int i=p;i<ds.n-1;i++){
        ds.A[i]=ds.A[i+1];
    }
    ds.n=ds.n-1;

}
// tim kiem phan tu
void TimKiem(DSKe ds,int x){
    int p=0;
    int d=0;
    int B[10];
    while(p<ds.n){
        if(ds.A[p]==x){
            B[d]=p;
            d++;
        }
        p+=1;
    }
    if(d>0){
        printf("Cac vi tri tim thay: ");
        for(int i=0;i<d;i++){
            printf("%d ",B[i]);
        }
    }
    else {
        printf("Khong co phan tu can tim!\n");
    }
}
int main(){
    DSKe ds;
    KhoiTao(ds);
    KiemTraDay(ds);
    KiemTraDay(ds);
    int x=5;
    ChenDau(ds,x);
    ChenCuoi(ds,x);
    int p;
    scanf("%d",&p);
    ChenGiua(ds,x,p);
    DuyetDS(ds);
    XoaPhanTu(ds,p);
    int x1;
    scanf("%d",&x1);
    TimKiem(ds,x1);

}