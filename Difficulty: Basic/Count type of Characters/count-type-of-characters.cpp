class Solution {
  public:
    vector<int> count(string s) {
        vector<int> toReturn(4, 0);
        for(auto ch : s) {
            if(isupper(ch)) toReturn[0]++;
            if(islower(ch)) toReturn[1]++;
            if(isdigit(ch)) toReturn[2]++;
            if(ispunct(ch)) toReturn[3]++;
        }
        return toReturn;
    }
};