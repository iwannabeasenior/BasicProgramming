#include <stdio.h>
#include <math.h>
//Nguyễn Trung Thành -20215482
float get_hypotenuse(float x, float y) {
    float z=pow(x,2)+pow(y,2);
    return sqrt(z);
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}