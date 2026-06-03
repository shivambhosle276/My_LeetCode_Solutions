class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds,
               vector<int>& vis, vector<vector<int>>& ans)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ds.push_back(nums[i]);

                solve(nums, ds, vis, ans);

                ds.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(), 0);

        solve(nums, ds, vis, ans);
        return ans;
    }
};