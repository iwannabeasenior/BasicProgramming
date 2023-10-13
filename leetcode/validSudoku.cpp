#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIsValid(vector<vector<char>>& board, char c, int x, int y){

        for (int j = 0; j < 9; j++) {
            if (j != y && board[x][j] == c) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (i != x && board[i][y] == c) return false;
        }

        int a = x/3; int b = y/3;
        for (int i = 3*a; i < 3*(a+1); i++) {
            for (int j = 3*b; j < 3*(b+1); j++) {
                if (i != x && j !=y && board[i][j] == c) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !checkIsValid(board, board[i][j], i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};

// c2 : 
class Solution {
public: 
    bool isValidSudoku(vector<vector<char>>& board) {
        int nums1[9][9] = {0};
        int nums2[9][9] = {0};
        int nums3[9][9] = {0};
        
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3; 
                    if (nums1[j][num] || nums2[i][num] || nums3[k][num]) return false;
                    nums1[j][num] = nums2[i][num] = nums3[k][num] = 1;
                }
            }
        }
        return true;
    }
};

int main(){

}