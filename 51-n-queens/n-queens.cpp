
void backtracking(vector<string>& chessBoard,vector<vector<string>>& ans,unordered_map<int,int>& left,unordered_map<int,int>& lowerDiagonal,unordered_map<int,int>& upperDiagonal,int& n,int col){
    if( col == n){
        ans.push_back(chessBoard);
        return;
    }

    for(int row = 0; row < n; row++){ 
        
        if(left[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[row-col] == 0){
           
            left[row]++; lowerDiagonal[row+col]++ ; upperDiagonal[row-col]++;
            chessBoard[row][col] = 'Q';
           
            backtracking(chessBoard,ans,left,lowerDiagonal,upperDiagonal,n,col+1);
           
            chessBoard[row][col] = '.';
            left[row] -- ; lowerDiagonal[row+col] -- ; upperDiagonal[row-col] -- ;
        }
    }
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        
        vector<string> chessBoard(n, string(n,'.'));
       
        unordered_map<int,int> left; 
        unordered_map<int,int> lowerDiagonal; 
        unordered_map<int,int> upperDiagonal; 
        
        backtracking(chessBoard,ans,left,lowerDiagonal,upperDiagonal,n,0);
        return ans;
    }
};