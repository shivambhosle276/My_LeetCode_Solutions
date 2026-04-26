class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& dfsvis,
             stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, dfsvis, st, adj)) return true;
            } else if (dfsvis[it]) return true;  
        }
        dfsvis[node] = 0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites)
            adj[it[1]].push_back(it[0]);  

        stack<int> st;
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, dfsvis, st, adj))
                    return {};  
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};