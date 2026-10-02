class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        long long sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int mn = nums[i];
            int mx = nums[i];

            for(int j = i; j < n; j++)
            {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);

                long long ans = (long long)mx - mn;

                sum += ans;
            }
        }

        return sum;
    }
};