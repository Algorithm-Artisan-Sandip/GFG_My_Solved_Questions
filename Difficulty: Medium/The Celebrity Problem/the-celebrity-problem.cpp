// Approach 3: OPTIMAL : T.C: O(n), S.C: O(1)
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int a = 0, b = mat.size()-1;
        while(a<b) {
            // a knows b, so a can not be celeb
            if(mat[a][b] == 1) a++; 
            // a does not know b, so b can not be celeb
            else b--;
        }
        
        int cand = a;
        for(int i=0; i<mat.size(); i++) {
            // omit the diagonal element : 
            if(i == cand) continue;
            // cand is celeb only if cand does not know i but i knows cand
            if(mat[i][cand] == 0 || mat[cand][i] == 1) return -1;
        }
        return cand;
    }
};