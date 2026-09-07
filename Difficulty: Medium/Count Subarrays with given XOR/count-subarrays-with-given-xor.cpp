class Solution {
  public:
    long subarrayXor(vector<int> &nums, int k) {
        // code here
        unordered_map<int, int> freq;

                int xr = 0;
                int count = 0;

                // Empty prefix XOR
                freq[0] = 1;

                for (int num : nums) {
                    // Current prefix XOR
                    xr ^= num;

                    // We need previous prefix XOR = xr ^ k
                    int required = xr ^ k;

                    // Add all previous occurrences
                    count += freq[required];

                    // Store current prefix XOR
                    freq[xr]++;
                }

                return count;
    }
};