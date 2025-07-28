// User function template in C++

class Solution {
  private:
    // Pure Recursive Solution : T.C: O(2^n), S.C: O(n) : 
    // int findAns(int n, int m) {
    //     if(n == 0 && m == 0) return 1;
    //     if(n<0 || m<0) return 0;
    //     int up = findAns(n-1, m);
    //     int left = findAns(n, m-1);
    //     return up + left;
    // }
    
    // Brute DP : Memorization : T.C: O(n*m), S.C:(n-1 + m-1 + n*m) : 
    int findAns(int n, int m, vector<vector<int>>& dp) {    
        if(n == 0 && m == 0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int up = findAns(n-1, m, dp);
        int left = findAns(n, m-1, dp);
        return dp[n][m] = up + left;
    }
    
    // Better DP
  public:
    int NumberOfPath(int a, int b) {
        // For Pure Recursive Solution : 
        // int ans = findAns(a-1, b-1);
        // return ans;
        
        // For Memorization and Tabulation : 
        vector<vector<int>> dp(a, vector<int>(b, -1));
        int ans = findAns(a-1, b-1, dp);
        return ans;
    }
};
