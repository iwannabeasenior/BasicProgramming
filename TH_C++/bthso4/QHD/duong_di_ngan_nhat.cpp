/*
Bài luyện tập: Cho đồ thị vô hướng G có N
đỉnh (N≤1000) và các cạnh có trọng số dương. Tìm đường đi ngắn nhất từ đỉnh 1 đến đỉnh N
hoặc thông báo không tồn tại đường đi. Gợi ý: Tại mỗi bước, chọn ra trong số các đỉnh chưa thăm mà có đường đi từ 1,
chọn ra đỉnh có đường đi ngắn nhất.
*/
//  dijsktra
// cũng tư tưởng giải bài toán con tối ưu (không phải gối nhau)
/*
Quy hoạch động
-Bài toán ban đầu nên có thể được phân chia thành các bài toán con gối nhau nhỏ hơn.(dạng 1)
-Lời giải tối ưu của bài toán có thể thu được bởi sử dụng lời giải tối ưu của các bài toán con.(dạng 2)
-Giải thuật Qui hoạch động sử dụng phương pháp lưu trữ (Memoization) – tức là chúng ta lưu trữ lời giải của các bài toán con đã giải,
và nếu sau này chúng ta cần giải lại chính bài toán đó thì chúng ta có thể lấy và sử dụng kết quả đã được tính toán.(điểm chung dạng 1 và 2)
*/
#include<iostream>
using namespace std;
int main(int argc, char){
    int n;
    cin >> n;  
}


