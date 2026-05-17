class DisjointSet{
public:
   vector<int> rank,parent,size; 
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
   int findpar(int node)
    {
        if(parent[node]==node)return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int up_u=findpar(u);
        int up_v=findpar(v);
        if(up_u==up_v)return;
        if(rank[up_u]<rank[up_v])
        {
            parent[up_u]=up_v;

        }
        else if(rank[up_u]>rank[up_v])
        {
            parent[up_v]=up_u;
        }
        else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxr=0;
        int maxc=0;
        for(auto it:stones)
        {
             maxr=max(maxr,it[0]);
             maxc=max(maxc,it[1]);
        }
        DisjointSet ds(maxr+maxc+1);
        unordered_map<int,int> stonesNodes;
        for(auto it:stones)
        {
            int noder=it[0];
            int nodec=it[1] + maxr+1;
            ds.unionbyrank(noder,nodec);
            stonesNodes[noder]=1;
            stonesNodes[nodec]=1;
        }
        int cnt=0;
        for(auto it:stonesNodes)
        {
            if(ds.findpar(it.first)==it.first)
            {
                cnt++;
            }
        }
        return n-cnt;
    }
};