class Solution {
public:
    int solve(vector<int>& coins, int n, int amount,vector<vector<int>>&dp) {
        if (n == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }
        if(dp[n][amount]!=-1)return dp[n][amount];

        int nottake = solve(coins, n - 1, amount,dp);

        int take = 1e9;
        if (coins[n] <= amount) {
            take = 1 + solve(coins, n, amount - coins[n],dp);
        }

        return dp[n][amount]=min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(coins, n - 1, amount,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};