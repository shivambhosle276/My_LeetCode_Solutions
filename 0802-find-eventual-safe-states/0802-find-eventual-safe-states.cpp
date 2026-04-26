class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjrev[n];
vector<int> indeg(n, 0);  // ✅

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> safenodes;       // fix: vecto → vector

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)       // fix: indeg[i] not indeg
                q.push(i);           // fix: missing semicolon
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safenodes.push_back(node);  // fix: ppush_back → push_back
            for (auto it : adjrev[node]) {
                indeg[it]--;
                if (indeg[it] == 0) q.push(it);
            }
        }

        sort(safenodes.begin(), safenodes.end());  // fix: saenods → safenodes
        return safenodes;
    }
};