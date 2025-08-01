class Solution {
public:
    int longestUniqueSubstring(string &s) {
        // Table to store the last index of each character (assuming lowercase letters only)
        vector<int> table(26, -1); 
        int left = 0, right = 0;  // Sliding window pointers
        int maxLen = 0;           // To store the maximum length of unique substring
        // Iterate through the string with the right pointer
        while (right < s.size()) {
            int idx = s[right] - 'a';  // Convert character to index (0 to 25)
            // If the current character was seen before and is inside the current window
            if (table[idx] >= left) {
                // Move the left pointer just after the previous occurrence to maintain uniqueness
                left = table[idx] + 1;
            }
            // Update the last seen index of the current character
            table[idx] = right;
            // Update the maximum length of unique substring found so far
            maxLen = max(maxLen, right - left + 1);
            // Move the right pointer forward
            right++;
        }

        return maxLen;
    }
};
