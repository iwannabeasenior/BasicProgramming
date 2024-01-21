#include <stdio.h>
int main(){
    
    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("%p\n",&a[i]);  
    return 0;
}