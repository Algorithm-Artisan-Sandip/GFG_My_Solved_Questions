//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
  //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        //Your code here
        unordered_set<int> st;
        for(int i=0; i<N; i++)
          st.insert(arr[i]);  // it will store only the unique elements

        int maxCnt = 1;
        for(auto it : st) {
            if(st.find(it-1) == st.end()) {  // finding the smallest number in a sequence
                int x = it;
                int cnt = 0;
                while(st.find(x) != st.end()) {
                    x++;
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        
        return maxCnt;
    }
};


//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends