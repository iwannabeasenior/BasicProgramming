#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int** ptr1=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        ptr1[i]=(int *)malloc(n*sizeof(int ));
    }
    int** ptr2=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        ptr2[i]=(int *)malloc(n*sizeof(int ));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(ptr1+i)+j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(ptr2+i)+j);
        }
    }
    int** ptr3=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        ptr3[i]=(int *)malloc(n*sizeof(int ));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ptr3[i][j]=0;
        }
    }
    int** ptr4=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        ptr2[i]=(int *)malloc(n*sizeof(int ));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           ptr4[i][j]=0;
        }
    }
    int tong=0;
    int tich=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ptr3[i][j]=ptr1[i][j]+ptr2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ptr4[i][j]=ptr1[i][k]*ptr2[k][j];
            }
        }
    }
    printf("ma tran tong cua 2 ma tran la :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",ptr3[i][j]);
        }
        printf("\n");
    }
    printf("ma tran tich cua 2 ma tran la :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",ptr4[i][j]);
        }
        printf("\n");
    }
}