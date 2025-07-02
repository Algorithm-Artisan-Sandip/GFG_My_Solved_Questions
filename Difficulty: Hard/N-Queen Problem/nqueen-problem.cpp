// User function Template for C++

class Solution {
  private:
    bool isSafe(int row, int col, vector<string>& str, int n) {
        int dupRow = row;
        int dupCol = col;
        
        // Upper-Left : 
        while(row>=0 && col >=0) {
            if(str[row][col] == 'Q') return false;
            row--; col--;
        }
        // left : 
        row = dupRow; col = dupCol;
        while(col >= 0) {
            if(str[row][col] == 'Q') return false;
            col--;
        }
        // bottom-left : 
        row = dupRow; col = dupCol;
        while(row<n && col >= 0) {
            if(str[row][col] == 'Q') return false;
            row++; col--;
        }
        return true;
    }
    void findAns(int n, vector<int>& ans, vector<vector<int>>& finalAns, vector<string>& str, int col) {
        if(col == n) {
            finalAns.push_back(ans);
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, str, n)) {
                str[row][col] = 'Q';
                ans.push_back(row+1);
                findAns(n, ans, finalAns, str, col+1);
                // backtrack : 
                ans.pop_back();
                str[row][col] = '.';
            }
        }
    }
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> finalAns;
        vector<int> ans;
        vector<string> str(n, string(n, '.'));
        findAns(n, ans, finalAns, str, 0);
        return finalAns;
    }
};