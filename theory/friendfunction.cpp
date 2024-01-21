#include<iostream>
using namespace std;
class friend_function {
    private:
        int a;
        public :
        friend void hello(friend_function ff);
};
// ham hello khong la thanh vien cua friend_function class
void  hello(friend_function ff){
    ff.a=1;
    cout<<"hello";
}
int main(){
    friend_function ff;
    hello(ff);
}