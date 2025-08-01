class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int right = 0, left = 0;
        int maxLen = 0;
        int zeros = 0;
        while(right < arr.size()) {
            if(arr[right] == 0) {
                zeros++;
                if(zeros > k) {
                    while(zeros != k) {
                        if(arr[left] == 0)
                            zeros--;
                        left++;
                    }
                }
            }
            if(zeros <= k) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};
