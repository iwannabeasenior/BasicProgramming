//CPP 
#include <bits/stdc++.h> 
using namespace std;

const int P=1e6+3;

struct HashTable{
    vector<int> h[P];
    public :
        void insert(int key){
            int index=hashfunc(key);
            for(auto p: h[index]){
                if(p==key){
                    return ;
                }
            }
            h[index].emplace_back(key);
        }
        bool find(int key){
            int index=hashfunc(key);
            for(auto p: h[index]){
                if(p==key){
                    return true;
                }
            }
            return false;
        }
    private: 
        int hashfunc(int key){
            return key%P;
        }
};
int main() 
{ 

    int n;
    cin >> n;
    int number = 0;
    map<int, int> m;
    HashTable hash;
    for (int i = 0; i < n; i++) {
        cin >> number;
        if(hash.find(number)) {
            cout << 1 << endl;
        }
        else {
            hash.insert(number);
            cout << 0 << endl;
        }
    }
}