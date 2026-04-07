#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubBoxValid(int i, int j, vector<vector<char>>& board){
        set<char>st;
        int countAq = 0;
        for(int row = i; row < i + 3; row++){
            for(int col = j; col < j + 3; col++){
                if(board[row][col] != '.'){
                    countAq++;
                    st.insert(board[row][col]);
                }
            }
        }
        return countAq == st.size();
    }

    bool validateCol(int col, vector<vector<char>>& board){
        set<char> st;

        for(int row = 0; row < 9; row++){
            char val = board[row][col];

            if(val == '.') continue;

            if(st.count(val)) return false;

            st.insert(val);
        }

        return true;
    }
    bool validateRow(int row, vector<vector<char>>& board){
        set<char> st;

        for(int col = 0; col < 9; col++){
            char val = board[row][col];

            if(val == '.') continue;

            if(st.count(val)) return false; 

            st.insert(val);
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = 9;
        int n = 9;
        for(int i = 0; i < n; i+=3){
            for(int j = 0; j < n; j+=3){
                cout<<i<<" "<<j<<endl;
                if(!checkSubBoxValid(i, j, board)){
                    return false;
                }
            }
        }
        //validate rows
        for(int i = 0; i < m; i++){
            if(!validateRow(i, board)){
                return false;
            }
            if(!validateCol(i, board)){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << s.isValidSudoku(board) << endl;
    return 0;
}
