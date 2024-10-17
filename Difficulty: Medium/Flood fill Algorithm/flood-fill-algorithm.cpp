//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    void bfs(int n, int m, int sr, int sc, vector<vector<int>>& image, int color) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // maintaining initial state : 
        visited[sr][sc] = true;
        q.push({sr, sc});
        
        int original = image[sr][sc];
        image[sr][sc] = color;
        
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;
            
            for(int i=0; i<4; i++) {
                int newRow = r + row[i];
                int newCol = c + col[i];
                
                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && image[newRow][newCol] == original && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    image[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        
        bfs(n, m, sr, sc, image, newColor);
        
        return image;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends