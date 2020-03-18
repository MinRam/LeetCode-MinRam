/**
 * @Problem https://leetcode.com/problems/valid-sudoku/
 * @Author MinRam
 * @Date  10/30/2019
 */

static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}(); 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rm(9);
        vector<int> cm(9);
        vector<int> sm(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int d=board[i][j]-'1';
                int m=1<<d;
                int combined=rm[i]|cm[j]|sm[(i/3)*3+(j/3)];
                if(combined&m)return false;
                rm[i]|=m; cm[j]|=m; sm[(i/3)*3+(j/3)]|=m;
            }
        }
        return true;
    }
};