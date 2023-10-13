#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Nguyen Trung Thanh - 20215482
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> :: iterator ptr = a.begin();
    for (ptr = a.begin(); ptr < a.end(); ptr++){
        if (*ptr % 2 == 0){
            a.erase(ptr);
            ptr--;
        }
    }
    
}

bool comparator (const int &x, const int &y){
        if (x > y) return true;
        else return false;
}
void sort_decrease(vector<int> &a) {
    /*****************
    # YOUR CODE HERE #
    *****************/ 
    sort(a.begin(), a.end(), comparator);
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    vector<int> c;
    int i = 0;
    int j = 0;
    while (i < (int)a.size() && j < (int)b.size())
    {
        if (a[i] < b[j]){
            c.push_back(b[j]);
            j++;
        }
        else{
            c.push_back(a[i]);
            i++;
        }
    }
    
    if (i == (int)a.size()){
        while (j < (int)b.size()){
            c.push_back(b[j]);
            j++;
        }
    }
    else {
        while (i < (int)a.size()){
            c.push_back(a[i]);
            i++;
        }
    }
    
    return c;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}