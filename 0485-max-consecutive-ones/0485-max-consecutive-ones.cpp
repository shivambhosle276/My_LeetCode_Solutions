class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)c++;
            maxi=max(maxi,c);
            if(nums[i]==0)c=0;
        }
        return maxi;
    }
};