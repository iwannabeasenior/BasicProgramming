#include <bits/stdc++.h>
using namespace std;
  
// Recursive function to 
// reverse digits of num
int reverseDigits(int num)
{
    static int rev_num = 0;
    static int base_pos = 1;
    if (num > 0) 
    {
        reverseDigits(num / 10);
        rev_num += (num % 10) * base_pos;
        base_pos *= 10;
    }
    return rev_num;
}
  
// Driver Code
int main()
{
    int num = 4562;
    cout << "Reverse of no. is " << 
             reverseDigits(num);
    return 0;
}