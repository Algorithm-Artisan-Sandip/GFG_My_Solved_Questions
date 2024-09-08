//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
    int binSearchFirst(int arr[], int n, int x) {
        int left = 0, right = n-1;
        int ans = -1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(arr[mid] == x) {
                ans = mid;
                right = mid-1;
            }
            
            else if(arr[mid] > x) right = mid-1;
            else left = mid+1;
        }
        
        return ans;
    }
    
    int binSearchLast(int arr[], int n, int x) {
        int left = 0, right = n-1;
        int ans = -1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(arr[mid] == x) {
                ans = mid;
                left = mid+1;
            }
            
            else if(arr[mid] > x) right = mid-1;
            else left = mid+1;
        }
        
        return ans;
    }

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    // finding the first occurence : 
	    int firstOcc = binSearchFirst(arr, n, x);
	    
	    // finding the last occurence : 
	    int lastOcc = binSearchLast(arr, n, x);
	    
	    int totalOcc = lastOcc - firstOcc + 1;
	    
	   // return totalOcc;
	   if(lastOcc == -1) return 0;
	   return totalOcc;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends