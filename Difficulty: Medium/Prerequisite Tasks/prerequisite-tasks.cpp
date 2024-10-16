//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void topoSort(int n, vector<int>& topoOrder, unordered_map<int, list<int>>& adjList) {
        queue<int> q;
        vector<int> indegree(n, 0);
        
        // storing the indegrees : 
        for(auto it : adjList) {
            for(auto nbr : it.second) {
                indegree[nbr]++;
            }
        } 
        
        // storing the nodes with zero indegree in the queue : 
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) 
                q.push(i);
        }
        
        // actual logic of bfs : 
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);
            
            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) 
                    q.push(nbr);
            }
        }
    }

public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    // preparing the adjacency list : 
	    unordered_map<int, list<int>> adjList;
	    for(auto it : prerequisites) {
	        int u = it.first;
	        int v = it.second;
	        adjList[v].push_back(u);
	    }
	    
	    // preparing the topologically sorted order : 
	    vector<int> topoOrder;
	    topoSort(N, topoOrder, adjList);
	    
	    // if topo logi
	    if(topoOrder.size() == N) return true;
	    else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends