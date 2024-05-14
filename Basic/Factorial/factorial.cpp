//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int findFact(long long int N) {
        if(N==1) return 1;
        else {
            return N * findFact(N-1);
        }
    }
    long long int factorial(long long int N){
        if(N==0 || N==1) return 1;
        else{
            return findFact(N);
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends