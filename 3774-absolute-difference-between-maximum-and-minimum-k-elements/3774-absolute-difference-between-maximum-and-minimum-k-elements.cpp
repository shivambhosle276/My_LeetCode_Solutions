class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum1=0;
        int sum2=0;
        int s=k;
    for(int i=0;i<nums.size();i++)
    {
        if(k>0)
        {
            sum1+=nums[i];
            k--;
        }
    }
    k=s;
    for(int i=nums.size()-1;i>=0;i--)
    {
        if(k>0)
        {
            sum2+=nums[i];
            k--;
        }
    }
        return abs(sum1-sum2);
    }
};