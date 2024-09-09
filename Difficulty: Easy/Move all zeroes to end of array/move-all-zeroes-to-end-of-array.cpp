//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// class Solution{
// public:
// 	void pushZerosToEnd(int arr[], int n) {
// 	    // code here
	    
// 	}
// };


// Brute Force : T.C: O(n) , S.C: O(1) : 
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    vector<int> temp;
	    
	    // storing the non zero elements : 
	    for(int i=0; i<n; i++) {
	        if(arr[i] != 0) temp.push_back(arr[i]);
	    }
	    
	    // replacing the non zero elements in the original array : 
	    for(int i=0; i<temp.size(); i++) {
	        arr[i] = temp[i];
	    }
	    
	    // putting all the remaining elements of arr as zero : 
	    for(int i=temp.size(); i<n; i++) {
	        arr[i] = 0;
	    }
	}
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends