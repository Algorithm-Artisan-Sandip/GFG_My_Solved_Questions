//{ Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
//User function Template for C++

void countSort(int arr[], int pos, int n) {
    vector<int> freq(10,0);
    
    for(int i=0; i<n; i++) {
        freq[(arr[i]/pos)%10]++;
    }
    
    for(int i=1; i<10; i++) {
        freq[i] += freq[i-1];
    }
    
    vector<int> temp(n);
    
    for(int i=n-1; i>=0; i--) {
        temp[--freq[(arr[i]/pos)%10]] = arr[i];
    }
    
    for(int i=0; i<n; i++) {
        arr[i] = temp[i];
    }
}

void radixSort(int arr[], int n) 
{
    int maxi = *max_element(arr, arr+n);
    
   for(int pos = 1; maxi/pos > 0; pos *= 10) {
       countSort(arr, pos, n);
   }
}


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    return 0; 
} 
// } Driver Code Ends