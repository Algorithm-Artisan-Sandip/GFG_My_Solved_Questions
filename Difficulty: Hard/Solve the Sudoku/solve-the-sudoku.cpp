
class Solution {
private:
    bool findAns(vector<vector<int>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    for (int c = 1; c <= 9; c++) {
                        if (isValid(row, col, c, board)) {
                            board[row][col] = c;
                            if (findAns(board)) return true;  // if we can fill the rest, return true
                            else board[row][col] = 0;  // else undo and try the next digit
                        }
                    }
                    return false;  // No valid digit could go here-> dead end
                }
            }
        }
        return true;  // No empty cells remain -> solved
    }

    bool isValid(int row, int col, int c, vector<vector<int>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;  // Check column
            if (board[row][i] == c) return false;  // Check row
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == c) return false;  // Check 3×3 sub‑grid
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<int>>& mat) {
        findAns(mat);
    }
};
