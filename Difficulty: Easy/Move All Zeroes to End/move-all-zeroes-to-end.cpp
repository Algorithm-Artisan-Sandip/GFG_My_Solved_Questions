class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int size = arr.size();
        if(size < 2) return;
        int nextPtr = 0;
        for(int i=0; i<size; i++) {
            if(arr[i] != 0) {
                swap(arr[nextPtr++], arr[i]);
            }
        }
    }
};