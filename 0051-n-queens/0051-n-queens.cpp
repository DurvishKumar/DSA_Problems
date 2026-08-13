class Solution {
public:
    void placingQueens(int n, vector<string>& board, vector<vector<string>>& ans, int col, vector<int>& leftrow, vector<int>& upperLeftDiagonal, vector<int>& lowerLeftDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(leftrow[ row ] == 0 && upperLeftDiagonal[ row + col ] == 0 && lowerLeftDiagonal[ n - 1 + col - row ] == 0){
                board[row][col] = 'Q';
                leftrow[ row ] = 1;
                upperLeftDiagonal[ row + col ] = 1;
                lowerLeftDiagonal[ n - 1 + col - row ] = 1;
                placingQueens(n, board, ans, col + 1, leftrow, upperLeftDiagonal, lowerLeftDiagonal);
                board[row][col] = '.';
                leftrow[ row ] = 0;
                upperLeftDiagonal[ row + col ] = 0;
                lowerLeftDiagonal[ n - 1 + col - row ] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        vector<int>leftrow(n,0);
        vector<int>upperLeftDiagonal(2*n-1, 0);
        vector<int>lowerLeftDiagonal(2*n-1, 0);
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        placingQueens(n, board, ans, 0, leftrow, upperLeftDiagonal, lowerLeftDiagonal);

        return ans;
    }
};