//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int firstOccr(int arr[], int n, int x) {
        int left = 0, right = n-1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] > x) right = mid-1;
            else if(arr[mid] < x) left = mid+1;
            else {
                ans = mid; 
                right = mid-1;
            }
        }
        return ans;
    }
    
    int lastOccr(int arr[], int n, int x) {
        int left = 0, right = n-1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(arr[mid] > x) right = mid-1;
            else if(arr[mid] < x) left = mid+1;
            else {
                ans = mid;
                left = mid+1;
            }
        }
        return ans;
    }

    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first = firstOccr(arr, n, x);
        int last = lastOccr(arr, n, x);
        
        return {first, last};
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends