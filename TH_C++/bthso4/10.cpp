#include<bits/stdc++.h>
using namespace std;
vector<string> vt1 ;
vector<string> vt2;
int n, q;
//Nguyen Trung Thanh - 20215482
// nhiều cái dùng đi dùng lại nên mình sẽ pre data trước, đỡ phải gọi hàm nhiều lần, sử dụng vector để lưu
int max_f_d(string source, string des){
    stringstream ss(source);
    stringstream sss(des);
    string word_sss;
    string word_ss;
    int count_max = 0;
    while (!sss.eof()){
        getline(sss, word_sss, ',');
        int count = 0;
        while (!ss.eof()){
            getline(ss, word_ss, ',');
            if (word_sss == word_ss){
                count++;
            }
        }
        if (count > count_max) count_max = count;
    }
    return count_max;
}

// count the number of occurences of s(word) in the source(a text)
int f_t_d(string source, string s){
    stringstream ss(source);
    string word;
    int count = 0;
    while (!ss.eof()){
        getline(ss, word, ',');
        if (word == s){
            count++;
        }
    }  
    return count;  
}
int d_f_t(vector<string> source, string des){
    int count = 0;
    for (int i = 0; i < n; i++){
        stringstream ss(source[i]);
        string word;
        while (!ss.eof()){
            // đọc từ ss ra word , cách nhau bởi dấu ','
            getline(ss, word, ',');
            if (word == des){
                count++;
                break;
            }
        }
    }
    return count;
}
// the number of text that contains des 
int diem_so_max(vector<string> source, string des){
    //find max_f_d, d=i
    double max = 0;
    int chiso = -1;

    for (int i = 0; i < n; i++){
        double score = 0;

        int maxfd = max_f_d(source[i], des);

        stringstream ss(des);
        
        string word ;

        while (!ss.eof()){

            getline(ss, word, ',');

            int dft = d_f_t(source, word);
         
            int ftd = f_t_d(source[i], word);
   
            // cout << "gia tri ftd: ";
            // cout << ftd << "\n";
            double tftd = 0.5 + 0.5*((double)ftd / maxfd);
         
            double idft = log2((double(n) / dft));
       
            if(ftd != 0) score += tftd * idft;

        }
        if (score > max){
            max = score;
            chiso = i+1;
        }

    }
    return chiso;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    cin >> n;
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        vt1.push_back(word);
    }
    
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> word;
        vt2.push_back(word);
    }
    

    for (int i = 0; i < q; i++){
        cout << diem_so_max(vt1, vt2[i]) << "\n";
    }

}