//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findKthMissing(vector<int>& arr1, vector<int>& arr2, int k) {
        unordered_map<int, int> freq;
        for(int i=0; i<arr2.size(); i++) {
            freq[arr2[i]]++;
        }
        int temp = 0;
        for(int i=0; i<arr1.size(); i++) {
            if(freq[arr1[i]] == 0) {
                temp++;
                if(temp == k) return arr1[i];
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To consume the newline character after t
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr1, arr2;

        // First array input
        while (ss >> num) {
            arr1.push_back(num);
        }

        // Second array input
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num) {
            arr2.push_back(num);
        }

        // k input
        cin >> num;
        int k = num;
        cin.ignore(); // Consume newline character

        Solution solution;
        int result = solution.findKthMissing(arr1, arr2, k);
        cout << result << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends