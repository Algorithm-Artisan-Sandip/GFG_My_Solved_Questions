class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> ansVec;
        int maxElement = INT_MIN;
        for(int i=arr.size()-1; i>=0; i--) {
            if(arr[i] >= maxElement) {
                ansVec.push_back(arr[i]);
                maxElement = arr[i];
            }
        }
        reverse(ansVec.begin(), ansVec.end());
        return ansVec;
    }
};