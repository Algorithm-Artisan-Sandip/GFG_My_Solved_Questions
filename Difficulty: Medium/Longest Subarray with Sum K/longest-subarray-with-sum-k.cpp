class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<long long, int> mp;

        long long prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {

            prefixSum += arr[i];

            // Subarray from index 0 to i
            if (prefixSum == k) {
                maxLen = i + 1;
            }

            // Check if a previous prefix sum exists
            if (mp.find(prefixSum - k) != mp.end()) {
                int len = i - mp[prefixSum - k];
                maxLen = max(maxLen, len);
            }

            // Store only the first occurrence
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};