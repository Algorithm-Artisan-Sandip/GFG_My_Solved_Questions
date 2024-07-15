//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string smallestNumber(int s, int d) {
        string str = "1", MM = "9";
        for(int i = 0; i < d -1; i++){
            str = str + '0';
            MM = MM + '9';
        }
        bool found = false;
        while(found == false){
            int sum = 0;
            for(int i = 0; i < str.size(); i++){
                sum += str[i] - '0';
            }
            if(sum == s){
                found = true;
            }
            else{
                int num = stoi(str);
                num++;
                str = to_string(num);
                if(str.size() > d){
                    str = "-1";
                    break;
                }
            }
        }
        return str;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends