//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPair(int target, vector<int> &arr) {
        int size = arr.size();
        int count = 0;
        
        for(int i=0; i<size; i++) {
            // handling the bou
            if(binary_search(arr.begin()+i+1, arr.end(), target-arr[i])) count++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        int k;
        cin >> k;
        string input;
        getline(cin, input);
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.countPair(k, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends