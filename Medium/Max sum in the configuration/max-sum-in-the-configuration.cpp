//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long r=0,ts=0,maxin=0;
        int i=0;
        while(i<n){
            ts+=a[i];
            r+=(i*1ll*a[i]);
            i++;
        }
        
        int j=0;
        maxin=max(maxin,r);
        while(j<n){
            r=r-(ts-a[j])+(a[j]*1ll*(n-1));
            maxin=max(maxin,r);
            j++;
        }
        return maxin;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends