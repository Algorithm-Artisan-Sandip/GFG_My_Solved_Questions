class Solution {
  private:
    int countOdds(vector<int>& arr, int k) {
        int right = 0, left = 0;
        int subarrCnt = 0;
        int oddCnt = 0;
        while(right < arr.size()) {
            if(arr[right] & 1) oddCnt++;
            while(oddCnt > k) {
                if(arr[left] & 1)
                    oddCnt--;
                left++;
            }
            if(oddCnt <= k)
                subarrCnt += (right-left+1);
            right++;
        }
        return subarrCnt;
    }
  public:
    int countSubarray(vector<int>& arr, int k) {
        return countOdds(arr, k) - countOdds(arr, k-1);
    }
};