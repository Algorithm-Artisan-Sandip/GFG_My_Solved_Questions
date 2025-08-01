class Solution {
public:
    int totalElements(vector<int>& arr) {
        int right = 0, left = 0;
        int maxLen = 0;
        unordered_map<int, int> mp;
        while(right < arr.size()) {
            mp[arr[right]]++;
            if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[arr[left]]--;
                    if(mp[arr[left]] == 0) {
                        mp.erase(arr[left]);
                    }
                    left++;
                }
            }
            if(mp.size() <= 2) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};