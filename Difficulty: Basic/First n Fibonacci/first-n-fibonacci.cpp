//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long int> arr;
        arr.push_back(1);
        if(n == 1) return arr;
        long long prev1 = 0;
        long long prev2 = 1;
        long long curr;
        for(long long int i=2; i<=n; i++) {
            curr = prev1+prev2;
            prev1 = prev2;
            prev2 = curr;
            arr.push_back(curr);
        }
        
        return arr;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends