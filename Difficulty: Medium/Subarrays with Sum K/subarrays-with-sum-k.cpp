class Solution {
  public:
    int cntSubarrays(vector<int> &nums, int k) {
        // code here
        int n = nums.size(); 
                unordered_map<int, int> prefixSumMap;
                int currentPrefixSum = 0, subarrayCount = 0;

               // Setting 0 in the map.
                prefixSumMap[0] = 1; 
                for (int i = 0; i < n; i++) {
                    // Add current element to the prefix sum:
                    currentPrefixSum += nums[i];

                    /*Calculate the value to 
                    remove (currentPrefixSum - k)*/
                    int sumToRemove = currentPrefixSum - k;

                    /* Add the number of subarrays
                     with the sum to be removed*/
                    subarrayCount += prefixSumMap[sumToRemove];

                    /* Update the count of current
                    prefix sum in the map*/
                    prefixSumMap[currentPrefixSum] += 1;
                }
                return subarrayCount;
    }
};