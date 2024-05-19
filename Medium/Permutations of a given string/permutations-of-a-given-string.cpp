//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
        void solve(string S, int i, vector<string> &ans){
            if(i>= S.length()){
                ans.push_back(S);
                return ;
            }
            for(int j = i; j < S.length(); j++ ){
                swap(S[i], S[j]);
                solve(S, i+1, ans);
                //swap all string as we change for permutation and return original string 
                swap(S[i], S[j]);
            }
        }
public:
    vector<string>find_permutation(string S){
        vector<string>ans;
            
        solve(S, 0, ans);
        sort(ans.begin(),ans.end());
        //remove unique permutations
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends