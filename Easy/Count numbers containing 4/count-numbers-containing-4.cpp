//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(int n){
        while(n!=0){
            int t = n%10;
            if(t==4){
                return true;
            }
            n /=10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        // code here
        int c=0;
        for(int i=1;i<=n;i++){
            if(check(i)){
                c++;
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends