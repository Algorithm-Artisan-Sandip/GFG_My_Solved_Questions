//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    void allPermutations(string &S, vector<string> &ansStr, int idx) {
        if(idx>=S.size()) {
            ansStr.push_back(S);
            return;
        }
        for(int i=idx; i<S.size(); i++) {
            swap(S[i],S[idx]);
            allPermutations(S,ansStr,idx+1);
            swap(S[i],S[idx]);
        }
    }
    vector<string> permutation(string S) {
        vector<string> ansStr;
        allPermutations(S,ansStr,0);
        sort(ansStr.begin(),ansStr.end());
        return ansStr;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends