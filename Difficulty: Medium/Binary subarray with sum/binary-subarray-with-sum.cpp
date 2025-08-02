class Solution {
  private:
    int givenSumSubarray(vector<int>& arr, int target) {
        int right = 0, left = 0;
        int subArrCnt = 0;
        int sum = 0;
        while(right < arr.size()) {
            if(arr[right] == 1) sum++;
            if(sum > target) {
                while(sum > target) {
                    if(arr[left] == 1)
                        sum--;
                    left++;
                }
            }
            if(sum <= target)
                subArrCnt += (right-left+1);
            right++;
        }
        return subArrCnt;
    }
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        int subarr_lessEqTarget = givenSumSubarray(arr, target);
        int subarr_lessEqTargetMinus1 = givenSumSubarray(arr, target-1);
        return subarr_lessEqTarget-subarr_lessEqTargetMinus1;
    }
};