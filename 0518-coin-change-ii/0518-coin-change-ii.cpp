class Solution {
public:
    int solve(int ind,int amount, vector<int>& coins ,vector<vector<int>> &dp)
    {   
        
        if(amount==0)return 1;
        if(amount<0 || ind==coins.size())return 0;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
         int take=solve(ind,amount-coins[ind],coins,dp);
         int notake=solve(ind+1,amount,coins,dp);
         return dp[ind][amount]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1, -1));
        return solve(0,amount,coins,dp);
       }
};