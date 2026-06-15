class Solution {
public:
    long long solve(int i,int j,string &s,string &t,vector<vector<long long>> &dp)
    {   
       
        if (j == t.size()) return 1; 
        if (i == s.size()) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])
        {
            int take=solve(i+1,j+1,s,t,dp);
            int notake=solve(i+1,j,s,t,dp);
            return dp[i][j]=take+notake;
        }
        else  return dp[i][j]=solve(i+1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        return solve(0,0,s,t,dp);
        
    }
};