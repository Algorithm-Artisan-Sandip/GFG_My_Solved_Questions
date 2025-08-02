class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int minLen = INT_MAX;      // To store the length of the smallest valid window
        int startIdx = -1;         // To store the starting index of the smallest valid window
        int i = 0;
        // Iterate through s1 to find subsequences matching s2
        while (i < n) {
            int j = 0;
            // Forward scan: try to find s2 as a subsequence in s1 starting from index i
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break;  // All characters in s2 matched
                }
                i++;
            }
            if (j < m) break;  // s2 cannot be matched anymore in the remaining string
            int end = i;       // End of current valid window where s2 is matched
            j = m - 1;
            // Backward scan: move back to find the minimal start position of the current valid window
            while (j >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                }
                i--;
            }
            int start = i + 1;  // Start index of the minimal window for this match
            int len = end - start + 1;
            // Update result if a smaller window is found
            if (len < minLen) {
                minLen = len;
                startIdx = start;
            }
            // Move i one step ahead of the current window's start to search for the next possible window
            i = start + 1;
        }
        // Return the smallest valid window if found, else return empty string
        return (startIdx == -1) ? "" : s1.substr(startIdx, minLen);
    }
};
