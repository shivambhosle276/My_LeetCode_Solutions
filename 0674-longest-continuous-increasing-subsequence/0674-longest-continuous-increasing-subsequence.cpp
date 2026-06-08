class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size(),len=1,ans=1;

        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]) len++;
            else len=1;
            
            ans= max(ans,len);
        }
        return ans;
    }
};