
class Solution {
public:

    int findParent(int node, vector<int> &parent)
    {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionBySize(int p1, int p2, vector<int> &size, vector<int> &parent)
    {
        int s1 = size[p1];
        int s2 = size[p2];

        if(s1<s2)
        {
            parent[p1] = p2;
            size[p2]+=size[p1];
        }
        else
        {
            parent[p2] = p1;
            size[p1]+=size[p2];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        vector<int>parent(n*n);
        vector<int>size(n*n);

        vector<int>nx = {-1,1,0,0};
        vector<int>ny = {0,0,-1,1};

        for(int i=0;i<n*n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int index = i*n+j;
                    for(int dir=0;dir<4;dir++)
                    {
                        int dx = i + nx[dir];
                        int dy = j + ny[dir];

                        if(dx>=0  &&  dx<n  &&  dy>=0  &&  dy<n  &&  grid[dx][dy])
                        {
                            int index2 = dx*n + dy;
                            int p1 = findParent(index,parent);
                            int p2 = findParent(index2,parent);
                            if(p1!=p2) unionBySize(p1,p2,size,parent);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int index = i*n+j;
                    int root = findParent(index,parent);
                    ans = max(ans,size[root]);
                }

                else
                {
                    int count = 1;
                    unordered_set<int>uniqueParent;
                    for(int dir=0;dir<4;dir++)
                    {
                        int dx = i + nx[dir];
                        int dy = j + ny[dir];

                        if(dx>=0  &&  dx<n  &&  dy>=0  &&  dy<n  &&  grid[dx][dy])
                        {
                            int index = dx*n+dy;
                            index = findParent(index,parent);
                            uniqueParent.insert(index);
                        }
                    }

                    for(auto &par:uniqueParent)
                    {
                        count+=size[par];
                    }

                    ans=max(ans,count);
                }
            }
        }

        return ans;
    }
};