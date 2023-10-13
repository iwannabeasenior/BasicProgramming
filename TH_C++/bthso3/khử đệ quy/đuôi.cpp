// khử đệ quy đuôi là kết quả chính là thằng cuối cùng không liên quan gì đến mấy thằng trước, ta dùng vòng lặp chạy đến
// đuôi để lấy kết quả luôn , như đệ quy bình thường thì tính A phải tính B rồi phải tích C ...
#include<iostream>
using namespace std;
int UCLN (int n, int m){
    while (m != 0){
        int temp = n;
        n = m;
        m = temp % m;
    }
    return n;
}
int main(){
    cout << UCLN(10, 4);
}