class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        int nrow[4]={-1,1,0,0};
        int ncol[4]={0,0,1,-1};
        vector<vector<int>> grid(n,vector<int>(m,0));
        queue<tuple<int,int,int>> q;
         sort(sources.begin(),sources.end(),[](auto &a,auto&b){
            return a[2]>b[2];
        });
        for(int i=0;i<sources.size();i++)
        {
            int r = sources[i][0];
            int c = sources[i][1];
            int color = sources[i][2];

            q.push({r,c,color});

            grid[r][c] = color;
        }
       
        while(!q.empty())
        {
          int row=get<0>(q.front());
          int col=get<1>(q.front());
          int color=get<2>(q.front());
          grid[row][col]=color;
          q.pop();
          for(int i=0;i<4;i++)
          {
            int r=row+nrow[i];
            int c=col+ncol[i];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0)
            {
                
                grid[r][c]=color;
                q.push({r,c,color});
            }
          }
        }
        return grid;
    }
};