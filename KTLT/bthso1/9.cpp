#include<stdio.h>
void indaycon(int a[],int x, int y){
        for(int i=x;i<=y;i++){
            printf("%d ",a[i]);

        }
        printf("\n");

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            indaycon(a,i,j);
        }
    }
}