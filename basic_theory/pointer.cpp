#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 110;
    int *z = &a;
    int *p = &a;
    int *q = &b;
    
    *p++ = *q++;
    cout << *p << " " << *q << endl;
    // bo nho dong cho mang 2 chieu
    int** ptr = new int* [10];
    for (int i = 0; i < 10; i++) {
        ptr[i] = new int [10];
    }
    
    for (int i = 0; i < 10; i++)
    {
        delete [] ptr[i];
    }
    delete [] ptr;
    
    int** mt = new int* [10];
    int *temp = new int [100];
    for (int i = 0; i < 10; i++){
        mt[i] = temp;
        temp += 10;
    }
    
 
}


