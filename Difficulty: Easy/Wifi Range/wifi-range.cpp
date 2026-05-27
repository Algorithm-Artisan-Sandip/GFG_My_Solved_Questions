class Solution {
  public:
    bool wifiRange(string &s, int x) {
        int n = s.length();
        // Imaginary router placed before the start of the string
        int lastRouterIdx = -x - 1;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(i - lastRouterIdx - 1 > 2 * x) {
                    return false;
                }
                lastRouterIdx = i;
            }
        }
        
        // Check if rooms after the last router are covered 
        if(n - 1 - lastRouterIdx > x) {
            return false;
        }

        // Return true if all rooms are covered
        return true;
    }
};
