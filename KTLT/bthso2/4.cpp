#include<iostream>
//Nguyễn Trung Thành-20215482
int cube(int x) {
   return x*x*x;
}

double cube(double f){
    return f*f*f;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}