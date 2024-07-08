//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int search(vector<int>& nums, int key) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Find the pivot (the index of the smallest element)
        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int pivot = start;

        // Step 2: Determine which part to search in
        start = 0;
        end = n - 1;
        // right part finding condition :
        if (key >= nums[pivot] && key <= nums[end]) {
            start = pivot;
        }
        // left part finding condition :
        else {
            end = pivot - 1;
        }

        // Step 3: Perform binary search in the chosen segment
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) return mid;
            else if (nums[mid] < key) start = mid + 1;
            else end = mid - 1;
        }

        return -1; // Key not found
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends