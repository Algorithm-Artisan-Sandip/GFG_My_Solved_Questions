class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        vector<int> lis;
        
        for(int i=0; i<size; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            if(it == lis.end()) {
                lis.push_back(arr[i]);
            }
            else {
                *it = arr[i];
            }
        }
        
        int toDelete = size - lis.size();
        return toDelete;
    }
};