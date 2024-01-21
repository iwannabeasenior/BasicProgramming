#include<iostream>

#define HASHTABLE_SIZE 100

using namespace std;

string hashtable[21];

const int hashtablesize = 21;

void insert(string s){
    
    int index = hashfunc(s);

    while(hashtable[index] != ""){
        index = (index+1) % hashtablesize;
    }

    hashtable[index] = s;
}
void search(string s){

    int index = hashfunc(s);

    // 1 là tìm dc s 2 là tìm đến cuối dãy rồi nhưng không ra s (tức là chuỗi "")
    while(hashtable[index] != "" && hashtable[index] != s){
        index = (index + 1) % hashtablesize; 
    }

    if(hashtable[index] == s){
        cout<< s << "is found" << endl;
    }
    else cout << s << "is not found" << endl;
   
}

int  hashfunc(string s){
    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        sum += s[i];
    }
    return sum % hashtablesize;
}

int main(){

}