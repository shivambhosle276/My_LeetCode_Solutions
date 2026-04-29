class Solution {
public:
    bool ispossible(vector<int>& nums,int k,int barr)
    {
        int allstu=1;
        int pages=0;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]>barr)return false;
          else if(pages+nums[i]>barr)
          {
            allstu++;
            pages=0;
            pages+=nums[i];
          }
          else pages+=nums[i];
        }
        if(allstu>k)return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*min_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ispossible(nums,k,mid))
            {
              ans=mid;
              high=mid-1  ;
            }
            else low=mid+1;
        }   
        return ans;    
    }
};