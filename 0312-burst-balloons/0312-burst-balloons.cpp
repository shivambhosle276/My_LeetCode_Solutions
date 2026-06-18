class Solution {
public:
    long long solve(int i, int j,
                    vector<int>& a,
                    vector<vector<long long>>& dp)
    {
        if(i > j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        long long maxi = 0;

        for(int k = i; k <= j; k++)
        {
            long long coins =
                1LL * a[i-1] * a[k] * a[j+1]
                + solve(i, k-1, a, dp)
                + solve(k+1, j, a, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<long long>> dp(
            n + 2,
            vector<long long>(n + 2, -1)
        );

        return solve(1, n - 2, nums, dp);
    }
};