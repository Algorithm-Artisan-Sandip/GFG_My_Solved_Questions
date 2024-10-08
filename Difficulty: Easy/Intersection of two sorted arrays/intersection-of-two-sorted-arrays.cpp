//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> ans;
        int i=0;
        int j=0;
    
        int n=a.size();
        int m=b.size();
        
        while(i<n && j<m){
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                int t=a[i];
                
                while(i<n && a[i]==t)
                    i++;
                while(j<m && b[j]==t)
                    j++;
            }
            else if(a[i] < b[j])
                i++;
            else
                j++;
        }
        
        if(ans.size()==0)
            ans.push_back(-1);
        return ans;
        
    }


};


//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.printIntersection(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends