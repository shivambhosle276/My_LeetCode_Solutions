class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n= nums.size();
        int maxi2=INT_MIN;
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        vector<int> res;
        for(int i=n-2;i>=0;i--)
        {  
            maxi=max(nums[i+1],maxi);
            mp[i]=maxi;
        }
        res.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
           maxi2=max(nums[i-1],maxi2);
           if(nums[i]>maxi2 || nums[i]>mp[i])res.push_back(nums[i]);
        }
        
        return res;
        
    }
};