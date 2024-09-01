//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// A[[]]
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> freq(3,0);
        for(int i=0; i<n; i++) {
            freq[arr[i]]++;
        }
        
        int idx = 0;
        for(int i=0; i<3; i++) {
            while(freq[i]--) {
                arr[idx++] = i;
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

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends