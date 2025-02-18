//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int j = 0;     // to track the numbers in the array
        int cnt = 0;  // to track the missing no. count
        for(int i=0; i<arr.size(); i++) {
            j++;                           // incrementing in each iteration of the array
            while(j != arr[i]) {           // checking if missing number is there
                cnt++;                     // if a number is missing then increase the count
                if(cnt == k) return j;     // if the missing number is the kth then simply return it
                j++;                       // if not then again increment it
            }
        }
        return j + (k-cnt);                // if the kth missing number is greater the greatest element in the array then add the ramainging counts.
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends