class Solution {
  private : 
    long long subarrSum(vector<int>& arr, long long target) {
        int right = 0, left = 0;
        long long sum = 0;
        long long subarrCnt = 0;
        while(right < arr.size()) {
            sum += arr[right];
            while(sum > target) {
                sum-=arr[left];
                left++;
            }
            subarrCnt += right-left+1;
            right++;
        }
        return subarrCnt;
    }
  public:
    long long countSubarray(int N, vector<int> arr, long long L, long long R) {
        return subarrSum(arr, R) - subarrSum(arr, L-1);
    }
};