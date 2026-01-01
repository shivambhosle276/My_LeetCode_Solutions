class Solution {
public:
    int n,m ;
        
   bool dfs(int ind,int row,int col,vector<vector<char>>& board,string word)
      {
        if (ind == word.size() - 1) return true;
        int drow[4]={-1,0,+1,0};
        int dcol[4]={0,1,0,-1};
         char temp = board[row][col];
            board[row][col] = '#';   // mark visite
        for(int i=0;i<4;i++)
        {
            int crow=row+drow[i];
            int ccol=col+dcol[i];
            if(crow>=0 && crow<n && ccol >=0 && ccol<m && board[crow][ccol]==word[ind+1])
            {
                if(dfs(ind+1,crow,ccol,board,word))
                {
                    return true;
                }
            }
        
        }
        board[row][col] = temp;
        return false;

      }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
       m = board[0].size();
        vector<vector<int>> vis;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {   int row=i;
                    int col=j;
                    if(dfs(0,row,col,board,word))
                    {
                        return true;
                    }
                }
                
            }
        }
         return false;

    }
};