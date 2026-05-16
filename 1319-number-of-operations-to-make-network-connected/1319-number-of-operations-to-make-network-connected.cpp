class DisjointSet{
public:
   vector<int> rank,parent,size; 
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++)
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
  int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntex=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)==ds.findpar(v))
            {
                cntex++;
            }
            else{
                ds.unionbyrank(u,v);
            }
        }
        int cntc=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)cntc++;
        }
        int ans =cntc-1;
        if(cntex>=ans)return ans ;
        return -1;

    }
};