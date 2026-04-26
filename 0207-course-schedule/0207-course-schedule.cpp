class Solution {
public:
    bool checkcycle(int node,vector<int> adj[],int vis[],int dfsvis [])
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(checkcycle(it,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[it])
            {
              return true ;
            }
        }
        dfsvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        int vis[numCourses],dfsvis[numCourses];
        memset(vis,0,sizeof vis);
        memset(dfsvis,0,sizeof dfsvis);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(checkcycle(i,adj,vis,dfsvis)){
                    return false;
                }
            }
        }
        return true;
    }
};