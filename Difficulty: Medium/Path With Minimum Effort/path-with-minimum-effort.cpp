//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        // code here
        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
        diff[0][0] = 0;
        
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, +1, 0, -1};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            auto topNode = pq.top();
            pq.pop();
            int currDiff = topNode.first;
            int r = topNode.second.first;
            int c = topNode.second.second;
            
            for(int i=0; i<4; i++) {
                int newRow = r + row[i];
                int newCol = c + col[i];
                
                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                    int newDiff = max(currDiff, abs(heights[r][c]-heights[newRow][newCol]));
                    
                    if(newDiff < diff[newRow][newCol]) {
                        diff[newRow][newCol] = newDiff;
                        pq.push({newDiff, {newRow, newCol}});
                    }
                }
            }
        }
        
        return diff[n-1][m-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends