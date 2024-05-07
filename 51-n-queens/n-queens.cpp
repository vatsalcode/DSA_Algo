class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));  
        vector<int> flags(5*n-2, 1);  
        solve(solutions, board, flags, 0, n);
        return solutions;
    }
    void solve(vector<vector<string>>& solutions, vector<string>& board, vector<int>& flags, int row, int n) {
        if (row == n) {  
            solutions.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (flags[col] && flags[n + row + col] && flags[4*n-2 + row - col]) {
                 
                board[row][col] = 'Q';
                 
                flags[col] = flags[n + row + col] = flags[4*n-2 + row - col] = 0;
                 
                solve(solutions, board, flags, row + 1, n);
                 
                board[row][col] = '.';
                flags[col] = flags[n + row + col] = flags[4*n-2 + row - col] = 1;
            }
        }
    }
};