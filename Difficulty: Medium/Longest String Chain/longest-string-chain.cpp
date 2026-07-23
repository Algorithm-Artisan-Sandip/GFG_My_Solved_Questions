class Solution {
    
private:    
    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    
public:
    int longestStringChain(vector<string>& words) {
        
        sort(words.begin(), words.end(),comp);
        
        unordered_map<string,int>dp;
        int maxi=1;
        
        for (auto &word : words) {
            int best=1;
            for (int i=0;i<word.size();i++){
                string prev=word.substr(0, i)+word.substr(i + 1);
                if (dp.find(prev)!=dp.end()) {
                    best=max(best,dp[prev] + 1);
                }
            }
            dp[word]=best;
            maxi=max(maxi, best);
        }
        
        return maxi;
    }
};