#include <stdio.h>

char* getMsg(){

    char s[] = "hello"; 

    return s;
//khong the return con tro vi khi ham thuc hien xong thi tat ca cac bien a[0],a[1]... deu bien mat het 
//lam cho a tro vao 1 cho lung tung tren bo nho nen khong the return duoc.
}

int main(){

    char* msg = getMsg();

    printf("%s\n",msg);

}

// #include<stdio.h>

// char getMsg(){
//     char* s="hello";
//     return s;
// }
// // hàm này thị dùng oke vì s chỉ địa chỉ của biến toàn cục nên khi hàm thoát ra biến không mất đi
// // nên khi trả về là trả về địa chỉ của biến toàn cục đó.
// int main(){
//     char msg=getMsg();
//     printf("%s\n",msg);
// }