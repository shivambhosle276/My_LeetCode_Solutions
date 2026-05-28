class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
private:
    bool isvalid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (isvalid(nr, nc, n) && grid[nr][nc] == 1) {
                        int node = row * n + col;
                        int adjNode = nr * n + nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int mx = 0;

        // Try converting each 0 to 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                set<int> components;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (isvalid(nr, nc, n) && grid[nr][nc] == 1) {
                        components.insert(ds.findpar(nr * n + nc));
                    }
                }

                int sizeTot = 0;

                for (auto parent : components) {
                    sizeTot += ds.size[parent];
                }

                mx = max(mx, sizeTot + 1);
            }
        }

       
        for (int cell = 0; cell < n * n; cell++) {
            mx = max(mx, ds.size[ds.findpar(cell)]);
        }

        return mx;
    }
};