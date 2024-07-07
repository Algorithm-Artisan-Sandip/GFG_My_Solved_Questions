//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

#define ll long long

vector<ll> printFirstNegativeInteger(ll arr[], ll N, ll k) {
    vector<ll> ans;
    deque<ll> dq;

    // Process the first window
    for (ll i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // Handle the first result after processing the first k elements
    if (!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the rest of the windows
    for (ll i = k; i < N; i++) {
        // Remove elements not in the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Add the current element to deque if it is negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // Add the first negative number of the current window to the result
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0); // If no negative numbers found in the current window, push 0
        }
    }

    return ans;
}
