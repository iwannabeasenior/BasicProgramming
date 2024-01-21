#include <stdio.h>
#include<stdlib.h>
int *a;
int n, tmp;
void doicho(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
   a=(int *)malloc(sizeof(int)*n);
    
    
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                doicho(&a[j],&a[j+1]);;
            }
        }
    }
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    delete [] a;
    return 0;
}