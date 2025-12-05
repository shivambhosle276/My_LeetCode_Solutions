class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int x : nums)
        {
            map[x]++;
            if(map[x]==2)
            {
                ans.push_back(x);
            }
        }
        return ans;
        
    }
};