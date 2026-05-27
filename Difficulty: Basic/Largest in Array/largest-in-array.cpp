class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxElement = INT_MIN;
        for(int num : arr) {
            if(maxElement < num)
                maxElement = num;
        }
        return maxElement;
    }
};
