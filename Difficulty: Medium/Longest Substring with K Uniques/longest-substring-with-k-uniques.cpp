class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int right = 0, left = 0;
        int maxLen = 0;
        while(right < s.size()) {
            mp[s[right]]++;
            if(mp.size() > k) {
                mp[s[left]]--;
                if(mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }
            if(mp.size() == k) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return (maxLen == 0) ? -1 : maxLen;
    }
};