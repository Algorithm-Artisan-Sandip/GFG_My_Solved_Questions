class Solution {
  private:
    bool isPossible(vector<int>& arr, int h, int k) {
        long long hours = 0;
        for(auto it : arr) {
            hours += it / k;
            if(it % k != 0) hours++;
            if(hours > h) return false;
        }
        return true;
    }
  public:
    int kokoEat(vector<int>& arr, int h) {
        int ans = 0;
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isPossible(arr, h, mid)) {  
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;  
            }
        }
        return ans;
    }
};
