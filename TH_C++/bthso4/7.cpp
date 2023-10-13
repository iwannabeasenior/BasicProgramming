// #include <iostream>
// #include <set>

// using namespace std;
//Nguyen Trung Thanh - 20215482
template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<T> c ;
    for (T t : a){
        c.insert(t);
    }
    for (T t : b){
        c.insert(t);
    }
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    # YOUR CODE HERE #
    *****************/
     set<T> c;
     for (T t : a){
        for (T t2 : b){
            if (t == t2){
                c.insert(t);
                break;
            }
        }
    }
    return c;
    
}

// template<class T>
// void print_set(const std::set<T> &a) {
//     for (const T &x : a) {
//         std::cout << x << ' ';
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::set<int> a = {1, 2, 3, 5, 7};
//     std::set<int> b = {2, 4, 5, 6, 9};
//     std::set<int> c = set_union(a, b);
//     std::set<int> d = set_intersection(a, b);
    
//     std::cout << "Union: "; print_set(c);
//     std::cout << "Intersection: "; print_set(d);

//     return 0;
// }