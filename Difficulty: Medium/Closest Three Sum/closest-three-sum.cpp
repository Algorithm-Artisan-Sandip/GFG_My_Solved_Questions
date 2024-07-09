//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
       sort(arr.begin(),arr.end());
       int ans=0;
       
       for(int i=0;i<arr.size();i++){
           
           int l=i+1;
           int h=arr.size()-1;
           int ele=arr[i];
           
           while(l<h){
               
               int sum=ele+arr[l]+arr[h];
               
               if(sum==target)
               return sum;
               
               else if(sum>target){
                   if(ans==0)
                   ans=sum-target;
                   else if(sum-target<=abs(ans))
                   ans=sum-target;
                   h--;
               }
               else{
                   if(ans==0)
                   ans=sum-target;
                   else if(abs(sum-target)<abs(ans))
                   ans=sum-target;
                   l++;
               }
           }
           
       }
       return target+ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends