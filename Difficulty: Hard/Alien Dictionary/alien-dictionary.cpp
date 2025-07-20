class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& adjList,
        vector<int>& indegree, vector<int>& isPresent
    ) {
        queue<int> q;
        // Only push letters that are present and have indegree == 0
        for (int i = 0; i < 26; i++) {
            if (isPresent[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adjList[u]) {
                if (--indegree[v] == 0) {
                    // Again, only push if v is actually present
                    if (isPresent[v]) {
                        q.push(v);
                    }
                }
            }
        }
        return topo;
    }
public:
    string findOrder(vector<string>& words) {
        vector<vector<int>> adjList(26);
        vector<int> indegree(26, 0), isPresent(26, 0);
        // 1) Mark which letters actually appear
        for (auto& w : words)
            for (char c : w)
                isPresent[c - 'a'] = 1;
        int letterCnt = accumulate(isPresent.begin(),isPresent.end(),0);
        // 2) Build edges from each adjacent pair of words
        for (int i = 0; i + 1 < (int)words.size(); i++) {
            const string &A = words[i], &B = words[i+1];
            int L = min(A.size(), B.size()), j = 0;
            // Find first mismatch
            for (; j < L; j++) {
                int u = A[j] - 'a', v = B[j] - 'a';
                if (u != v) {
                    // add edge u -> v if not already present
                    adjList[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
            // If no mismatch and A is longer than B, it's invalid
            if (j == L && A.size() > B.size())
                return "";
        }
        // 3) Topo‑sort only the present letters
        auto topo = topoSort(adjList, indegree, isPresent);
        // 4) Check for cycle (i.e. missing some present letters)
        if (topo.size() != letterCnt)
            return "";
        // 5) Build answer string
        string ans;
        ans.reserve(letterCnt);
        for (int x : topo)
            ans.push_back(char('a' + x));
        return ans;
    }
};
