#include <stdio.h>
//Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím. Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.
/**
 * Lưu ý: Khi viết hàm cấp phát bộ nhớ cho một ma trận hai chiều biểu diễn bởi con trỏ int **mt,
 nếu ta truyền con trỏ theo kiểu địa chỉ void allocate(int **mt, int m, int n) sẽ dẫn tới việc cấp phát bộ nhớ
  cho một bản sao của con trỏ **mt. Do đó, sau khi gọi hàm thì con trỏ **mt gốc vẫn không được cấp phát bộ nhớ. 
  Để cấp phát thành công cần truyền con trỏ theo dạng địa chỉ, ví dụ sử dụng con trỏ cấp 3 dạng int ***mt.

*/

    //#Allocate memory for the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/

void allocate_mem(int ***mt, int m, int n){
}
void input(int **mt, int m, int n){
    //#Input elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/ 
    
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    
    /*****************
    # YOUR CODE HERE #
    *****************/
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    
    /*****************
    # YOUR CODE HERE #
    *****************/
}

int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}