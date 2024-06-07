//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) 
    {
        vector<int> prefix(maxx+1,0);
        for(int i=0;i<n;i++)
        {
            int x = l[i];
            int y = r[i];
            if(y==maxx) prefix[x]++;
            else{
                prefix[x]++;
                prefix[y+1]--;
            }
        }
        for(int i=0;i<prefix.size();i++)
            if(i) prefix[i]+=prefix[i-1];
        int ans = 0;
        int cnt = 0;
        int temp = 0;
        for(int i=0;i<prefix.size();i++) {
            cnt = max(cnt,prefix[i]);
            if(cnt>temp){
                ans = i;
                temp = cnt;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends