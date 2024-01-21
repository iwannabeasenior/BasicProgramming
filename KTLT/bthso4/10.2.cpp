#include<bits/stdc++.h>
using namespace std;

int n, p;
vector<string> text;
vector<string> query;
vector<vector<string>> text_word;
vector<vector<pair<string, int>>> query_word;

void pre(){
    // tách các từ trong từng text 
    for (int i = 0; i < n; i++){
        stringstream ss(text[i]);
        string word;
        vector<string> v;
        while (!ss.eof()){
            getline(ss, word, ',');
            
            v.push_back(word);
        }
        text_word.push_back(v);
    }
    // tách các từ trong từng query
    for (int i = 0; i < p; i++){
        stringstream ss(query[i]);
        string word;
        vector<pair<string, int>> v2;
        while (!ss.eof()){
            getline(ss, word, ',');
            // số lần có mặt của word ở trong tất cả văn bản , d_f_t
            int count = 0;
            for (int j = 0; j < n; j++){
                for (string textWord : text_word[j]){
                    if (textWord == word){
                        count++;
                        break;
                    }        
                }
            }
            v2.push_back(make_pair(word, count));
            
        }
        query_word.push_back(v2);
    }
}
// số lần xuất hiện của t trong văn bản d
int f_t_d(vector<string> d, string t){
    int count = 0;
    for (string p : d){
        
        if (t == p){
             count++;
        }
    }
    return count ;
}
// số lần xuất hiện max trong văn bản d (mọi t)
int max_f_d(vector<string> text, vector<pair<string, int>> wordInQuery){
    int max = -10000;   
    for (pair<string, int> p : wordInQuery){
        int count = f_t_d(text, p.first);
        if (count > max){
            max = count;
        }
    }
    return max;
}

int addMaxScore(vector<pair<string, int>> vt1){
    double max = -1;
    int chiso = -1;
    for (int i = 0; i < n; i++){
        int score = 0;
        int maxfd = max_f_d(text_word[i], vt1);
        for (pair<string, int> p : vt1){
            double tftd = 0.5 + 0.5 * ((double)f_t_d(text_word[i], p.first) / maxfd);
            double idft = log2((double)n / p.second);
            if (f_t_d(text_word[i], p.first) > 0){
                score += tftd * idft;
            }
        }
        if (score > max){
            max = score;
            chiso = i;
        }
    }
    return chiso + 1;

}
int main(){

    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        text.push_back(s);
    }
    
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> s;
        query.push_back(s);
    }
    
    pre();
  
    for (int i = 0; i < p; i++){
        cout << addMaxScore(query_word[i]) << "\n";
    }
}
