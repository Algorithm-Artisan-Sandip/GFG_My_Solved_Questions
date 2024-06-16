//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    void sieve(vector<int>& primes, int n) {
        primes[0] = true;

        for (int i = 3; i * i <= n; i += 2) {
            if (primes[i / 2] == false) {
                for (int j = 3 * i; j <= n; j += 2 * i) {
                    primes[j / 2] = true;
                }
            }
        }
    }

    vector<int> getPrimes(int n) {
        vector<int> primes((n / 2) + 1, false); // Only store odd numbers and 2 in a compressed form
        sieve(primes, n);
        vector<int> ans;
        unordered_set<int> st;

        // Insert primes into the set
        for (int i = 0; i <= n; i++) {
            if (i == 2) {
                st.insert(i);
            } else if (i % 2 == 1 && primes[i / 2] == false) {
                st.insert(i);
            }
        }

        // Find the pair of primes that sum up to n
        for (int i = 0; i <= n; i++) {
            if (i == 2) {
                if (st.find(n - i) != st.end()) {
                    ans.push_back(i);
                    ans.push_back(n - i);
                    break;
                }
            } else if (i % 2 == 1 && primes[i / 2] == false) {
                if (st.find(n - i) != st.end()) {
                    ans.push_back(i);
                    ans.push_back(n - i);
                    break;
                }
            }
        }

        if (ans.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends