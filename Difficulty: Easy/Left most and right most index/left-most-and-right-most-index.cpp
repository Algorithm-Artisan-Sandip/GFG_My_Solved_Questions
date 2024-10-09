//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    int leftSearch(vector<long long>& arr, long long x) {
        long long left = 0, right = arr.size()-1;  
        long long ans = -1;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(arr[mid] > x) right = mid - 1;
            else if(arr[mid] < x) left = mid + 1;
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
    
    int rightSearch(vector<long long>& arr, long long x) {
        long long left = 0, right = arr.size()-1;  
        long long ans = -1;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            if(arr[mid] < x) left = mid + 1;
            else if(arr[mid] > x) right = mid - 1;
            else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
    
    pair<long, long> indexes(vector<long long> v, long long x) {
        int leftIdx = leftSearch(v, x);  
        int rightIdx = rightSearch(v, x); 
        
        return {leftIdx, rightIdx}; 
    }
};



//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends