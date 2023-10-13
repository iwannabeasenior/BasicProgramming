// khử bằng vòng lặp thì dùng vòng lặp để tính toán từ dưới lên trên còn đệ quy thông thường sẽ tính toán từ trên xuống dưới
#include<iostream>
using namespace std;
int tinhGiaiThua(int n){
    int k = 0;
    int temp = 1;
    while (k < n){
        k++;
        temp = temp * k;
    }
    return temp;
}
int main(){
    int n;
    cout << "Nhap gia tri n vao : ";
    cin >> n;
    cout << "gia tri cua " << n <<"! " <<"la: "<< tinhGiaiThua(n);
    
}