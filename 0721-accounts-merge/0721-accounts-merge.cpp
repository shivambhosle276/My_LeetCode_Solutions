class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int up_u = findpar(u);
        int up_v = findpar(v);

        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        }
        else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {

        int n = details.size();

        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < details[i].size(); j++) {

                string mail = details[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionbyrank(i, mapMailNode[mail]);
                }
            }
        }

  
        vector<string> mergedMail[n];

        for (auto it : mapMailNode) {

            string mail = it.first;

            int node = ds.findpar(it.second);

            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (mergedMail[i].size() == 0)
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

           
            temp.push_back(details[i][0]);

            for (auto mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};