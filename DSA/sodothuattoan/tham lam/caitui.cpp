#include<iostream>
using namespace std;
void swap (int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

int main(){
    int n;
    std::cin >> n;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int m[n];
    for (int i = 0; i < n; i++)
    {
        std :: cin >> m[i];
    }
    int sum;
    std:: cin >> sum;
    
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++){

            if ((float)a[j] / m[j] < (float)a[j + 1] / m[j + 1]){
                swap (a[j], a[j + 1]);
                swap (m[j], m[j + 1]);
            }
        }
    }
    int c[n];
    int sumMoney = 0;
    for (int  i = 0; i < n; i++)
    {   
        c[i] = sum / m[i];
        sum = sum % m[i];
        sumMoney += c[i] * a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std :: cout << c[i] << " ";
    }
    std :: cout << sumMoney;
    
    
}