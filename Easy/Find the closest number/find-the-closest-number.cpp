//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        vector<int> temp;
        int count=0;
        // Complete the function
        for(int i=0;i<n;i++)
        {
            temp.push_back(abs(arr[i]-k));
        }
        int temp1=temp[0];
        
        for(int i=0;i<temp.size();i++)
        {
            if(temp1>=temp[i])
            {
                temp1=temp[i];
                count=i;
            }
        }
        // cout<<count<<endl;
        // cout<<temp1<<endl;
        return arr[count];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends