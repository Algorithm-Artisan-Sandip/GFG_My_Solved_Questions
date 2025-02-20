//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    // most optimized approach : Logarithmic time complexity : 
    int maxConsecutiveOnes(int N)
    {
        int num = N;
        int count = 0;
        int ans = 0;
        while(num > 0) {
            if(num & 1) {
                count++;
                ans = max(ans, count);
            }
            else count = 0;
            num >>= 1;                  // right shift operator
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends