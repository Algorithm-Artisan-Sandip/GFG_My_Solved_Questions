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
    private:
    string decToBin(int n) {
        string str;
        while(n>0) {
            str += to_string(n%2);
            n /= 2;
        }
        return str;
    }

    public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        string str = decToBin(n);
        int count = 0, maxConsOne = 0;
        
        for(int i=0; i <str.size(); i++) {
            if(str[i] == '1') count++;
            else count = 0;
            maxConsOne = max(maxConsOne, count);
        }
        
        return maxConsOne;
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
	}
	return 0;
}
// } Driver Code Ends