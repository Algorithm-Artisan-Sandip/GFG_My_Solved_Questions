//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        double P = perimeter;
        double A = area;
        double sqrtTerm = sqrt(P * P - 24 * A);
        double dim1 = (P - sqrtTerm) / 12.0;
        double dim2 = (P / 4.0) - 2 * dim1;
        double vol = pow(dim1, 2) * dim2;
        
        return round(vol * 100.0) / 100.0;
    }
};


//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends