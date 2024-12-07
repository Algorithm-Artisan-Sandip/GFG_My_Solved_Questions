//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        int i = left;      
        int j = mid + 1;   
        int k = left; 
        int invCnt = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCnt += (mid - i + 1);
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
        return invCnt;
    }

    int mergeSortHelper(vector<int> &arr, vector<int> &temp, int left, int right) {
        int invCnt = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            invCnt += mergeSortHelper(arr, temp, left, mid);

            invCnt += mergeSortHelper(arr, temp, mid + 1, right);

            invCnt += merge(arr, temp, left, mid, right);
        }
        return invCnt;
    }

    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortHelper(arr, temp, 0, n-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends