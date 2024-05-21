//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int binarySearch(vector<int> &arr, int low, int hig, int x) {
        while(low <= hig) {
            int mid = low + (hig - low) / 2;
            if(arr[mid] == x)
                return mid;
            else if(arr[mid] < x)
                low = mid + 1;
            else
                hig = mid - 1;
        }
        
        return low;
    }

    vector<int> printKClosest(vector<int> &arr, int n, int k, int x) {
        int position = binarySearch(arr, 0, n - 1, x);
        int left = position - 1, right = position;
        vector<int> res;
        
        if(right < n and arr[right] == x)
            right++;
        
        while(k > 0 and left >= 0 and right < n) {
            int leftDiff = abs(arr[left] - x);
            int rightDiff = abs(arr[right] - x);
            
            if(leftDiff < rightDiff) 
                res.push_back(arr[left--]);
            
            else if(leftDiff > rightDiff) 
                res.push_back(arr[right++]);
            
            else {
                if(arr[right] > arr[left]) 
                    res.push_back(arr[right++]);
                else 
                    res.push_back(arr[left--]);
            }
            
            k--;
        }
        
        while(k > 0 and left >= 0) {
            res.push_back(arr[left--]);
            k--;
        }
        
        while(k > 0 and right < n) {
            res.push_back(arr[right++]);
            k--;
        }
            
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends