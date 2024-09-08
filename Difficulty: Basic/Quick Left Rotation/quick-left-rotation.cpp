//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    void leftRotate(vector<int>& arr, int k) {
        // Your code goes here
        int size = arr.size();
        k %= size;
        
        // rotating the first k elements : 
        reverse(arr.begin(), arr.begin()+k);
        
        // rotating the last n-k elements : 
        reverse(arr.begin()+k, arr.end());
        
        // rotating the entire array : 
        reverse(arr.begin(), arr.end());
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
        int k;
        cin >> k;
        cin.ignore(); // To discard any leftover newline characters
        Solution ob;
        ob.leftRotate(arr, k);
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends