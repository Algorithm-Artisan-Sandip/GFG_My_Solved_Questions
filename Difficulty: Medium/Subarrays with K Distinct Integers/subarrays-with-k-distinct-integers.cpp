class Solution {
  private:
    int subarrFind(vector<int>& arr, int k) {
        if(k == 0) return 0;
        int right = 0, left = 0;
        int subarrCnt = 0;
        int distinctCnt = 0;
        unordered_map<int, int> mp;
        while(right < arr.size()) {
            mp[arr[right]]++;
            if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[arr[left]]--;
                    if(mp[arr[left]] == 0)
                        mp.erase(arr[left]);
                    left++;
                }
            }
            if(mp.size() <= k)
                subarrCnt += (right-left+1);
            right++;
        }
        return subarrCnt;
    }
  public:
    int exactlyK(vector<int> &arr, int k) {
        return subarrFind(arr, k) - subarrFind(arr, k-1);
    }
};