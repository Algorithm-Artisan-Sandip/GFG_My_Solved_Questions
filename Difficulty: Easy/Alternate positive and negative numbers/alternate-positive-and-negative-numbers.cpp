//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        queue<int> pos;
        queue<int> neg;
        
        int size = arr.size();
        
        for(int i=0; i<size; i++) {
            if(arr[i] < 0) neg.push(arr[i]);
            else pos.push(arr[i]);
        }
        
        int i=0;
        while(!neg.empty() || !pos.empty()) {
            if(!pos.empty()) {
                arr[i++] = pos.front();
                pos.pop();
            }
            if(!neg.empty()) {
                arr[i++] = neg.front();
                neg.pop();
            }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends