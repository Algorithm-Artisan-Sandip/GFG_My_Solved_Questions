// User function template for C++

class Solution {
  public:
    string ExcelColumn(int N) {
        string ans = "";
        while(N--) {
            int remainder = N % 26;
            ans += char('A' + remainder);
            N /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};