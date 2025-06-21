// Optimal : T.C: O(2*n), S.C: O(2*n)
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st;
        for(int i=0; i<N; i++) {
            int a = asteroids[i];
            bool alive  = true;
            while(alive && !st.empty() && a < 0 && st.top() > 0) {
                if(st.top() < -a) {
                    st.pop();       // stack top asteroid is destroyed
                }
                else if(st.top() == -a) {
                    st.pop();
                    alive = false;  // stack top and current asteroid both are destroyed
                }
                else{
                    alive = false;  // current asteroid is destroyed
                }
            }
            if(alive) st.push(a);
        }
        int stackSize = st.size();
        vector<int> ans(stackSize);
        while(stackSize--) {
            ans[stackSize] = st.top();
            st.pop();
        }
        return ans;
    }
};