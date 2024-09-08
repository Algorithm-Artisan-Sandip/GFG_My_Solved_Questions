//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int> mapping;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            mapping[arr[i]]++;
        }
        
        for(int i=0; i<n; i++) {
            if(mapping[arr[i]] > 1) return i+1;
        }
        
        return -1;
        
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends