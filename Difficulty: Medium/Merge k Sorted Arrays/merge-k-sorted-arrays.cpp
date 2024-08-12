//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Info{
    public:
    int data;
    int rowIdx;
    int colIdx;
    
    Info(int a, int b, int c) {
        this->data = a;
        this->rowIdx = b;
        this->colIdx = c;
    }
};

class compare {
    public : 
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    void mergeKSortedArray(vector<vector<int>>& arr, int n, int k, vector<int>& ans) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        
        //process first k elements : 
        for(int i=0; i<k; i++) {
            int element = arr[i][0];
            Info* temp = new Info(element, i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()) {
            Info* temp = pq.top();
            pq.pop();
            int topData = temp->data;
            int topRow = temp->rowIdx;
            int topCol = temp->colIdx;
            
            // store in ans vector : 
            ans.push_back(topData);
            
            // next element for the same row, from which we just popped, so this should also be inserted.
            if(topCol + 1 < n) {
                //  this means there are still elements present in the row : 
                Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
                pq.push(newInfo);
            }
        }
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        mergeKSortedArray(arr, arr.size(), arr[0].size(), ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends