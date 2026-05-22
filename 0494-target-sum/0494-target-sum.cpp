class Solution {
public:
    int solve(int ind, vector<int>& nums, int target) {
        if (ind == nums.size() )
        {
           if(target == 0)
               return 1;
           else
               return 0;
        }
        int pos =  solve(ind + 1, nums, target - nums[ind]);
        int neg =  solve(ind + 1, nums, target + nums[ind]);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
          return solve(0, nums, target);
    }
};