//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int n, int sum);
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];  //array of size n
            
        for(int i = 0; i < n; i++)
            cin>>arr[i]; //Input the array
             
        int sum; 
        cin>>sum;
          
        cout<< sumExists(arr, n, sum) <<endl;    
            
	}
}
// } Driver Code Ends


//User function Template for C++

int sumExists(int arr[], int n, int sum){
    
    
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++)
        mpp[arr[i]] = i;
    
    for(int i=0; i<n; i++) {
        int more = sum - arr[i];
        if(mpp.find(more) != mpp.end() && mpp[more] != i)
            return 1;
    }
    
    return 0;
}