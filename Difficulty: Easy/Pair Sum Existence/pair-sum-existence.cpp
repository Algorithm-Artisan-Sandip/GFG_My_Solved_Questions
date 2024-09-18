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
int binSearch(int nums[], int target, int idx,int size) {
    int left = idx+1;
    int right = size-1;
    

    while(left <= right) {
        int mid = left + (right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

int sumExists(int nums[], int size, int target){
    sort(nums, nums+size);
    
    for(int i=0; i <size; i++) {
        int first = i;
        int last = binSearch(nums, target-nums[i], first, size);
        if(last != -1) return 1;
    }

    return 0;
}