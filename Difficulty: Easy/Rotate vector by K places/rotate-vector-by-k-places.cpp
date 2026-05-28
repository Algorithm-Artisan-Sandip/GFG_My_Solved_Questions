class Solution {
  public:
    vector<int> leftRotate(vector<int> &nums, int k) {
        int size = nums.size();
        if(size < 2) return nums;
        k %= size;
        if(k == 0) return nums;
        // rotate the entire array : 
        int i=0, j=size-1;
        while(i<j) {
            swap(nums[i++], nums[j--]);
        }
        
        // rotate the first n-k elements : 
        i=0; j=size-k-1;
        while(i<j) {
            swap(nums[i++], nums[j--]);
        }
        
        // rotate the last k elements : 
        i=size-k; j=size-1;
        while(i<j) {
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};
