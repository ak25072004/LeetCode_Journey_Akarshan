class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.'){
                    int b = (i / 3) * 3 + (j / 3);
                    row[i][board[i][j] - '0' - 1] = true;
                    col[j][board[i][j] - '0' - 1] = true;
                    box[b][board[i][j] - '0' - 1] = true;
                }
        solve(board, row, col, box);
    }

    bool solve(vector<vector<char>>& board, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& box){
        int b;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] == '.'){
                    b = (i / 3) * 3 + (j / 3);
                    for(int k = 0; k < 9; k++)
                        if(!row[i][k] && !col[j][k] && !box[b][k]){
                            row[i][k] = true;
                            col[j][k] = true;
                            box[b][k] = true;
                            board[i][j] = '0' + k + 1;
                            if(solve(board, row, col, box))
                                return true;
                            board[i][j] = '.';
                            row[i][k] = false;
                            col[j][k] = false;
                            box[b][k] = false;
                        }
                    return false;
                }
        return true;
    }
};