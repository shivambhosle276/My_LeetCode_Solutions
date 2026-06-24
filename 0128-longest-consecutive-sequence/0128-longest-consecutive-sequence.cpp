class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int len=1;
        int maxi=INT_MIN;
        if(nums.empty())return 0;
        else if (n==1)return 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+1==nums[i+1])len++;
            else if(nums[i+1]==nums[i])continue;
            else len=1;
            maxi=max(maxi,len);
        } 
        maxi=max(maxi,len);
        return maxi;
        
        
    }
};