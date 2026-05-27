class Solution {
  public:
    int search(vector<int>& arr, int x) {
        for(size_t i=0; i<arr.size(); i++) {
            if(x == arr[i]) return i;
        }
        return -1;
    }
};