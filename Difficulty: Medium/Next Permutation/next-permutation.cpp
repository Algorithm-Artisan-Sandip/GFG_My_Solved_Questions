//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // first find the first decreasing element : let position be 'x'
        int i = arr.size() - 2;
        while(i >= 0 && arr[i+1] <= arr[i]) i--;
        
        // find the number in left portion which is just greater than the element at 'x' :
        if(i >= 0) {
           int j = arr.size() - 1;
           while(arr[j] <= arr[i]) j--;
           // swap the two numbers :
            swap(arr[i], arr[j]);
        }
        
        // sort the number from x to the end : 
        reverse(arr.begin()+i+1, arr.end());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends