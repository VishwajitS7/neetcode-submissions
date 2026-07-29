class Solution {
public:
    bool solve(int ind, vector<vector<char>>& board, int i, int j, string& word){
        int N = board.size();
        int M = board[0].size();
        if(ind == word.size()){
            return true;
        }

        if(i<0 || i>=N || j<0 || j>=M || board[i][j] != word[ind]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = ' ';

        bool ans = solve(ind+1, board, i-1, j, word) || solve(ind+1, board, i+1, j, word) || solve(ind+1, board, i, j-1, word) ||solve(ind+1, board, i, j+1, word);

        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(0, board, i, j, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
