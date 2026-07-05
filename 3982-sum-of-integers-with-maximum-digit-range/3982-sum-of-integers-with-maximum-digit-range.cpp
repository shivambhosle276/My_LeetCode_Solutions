class Solution {
public:
    int solve(int m)
    {   vector<int> temp;
        while(m>0)
        {
            int r=m%10;
            temp.push_back(r);
            m=m/10;
        }
       int n = temp.size();

       int mini = *min_element(temp.begin(), temp.end());
       int maxi = *max_element(temp.begin(), temp.end());
       return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,solve(nums[i]));
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(solve(nums[i])==maxi)
            {
                sum+=nums[i];
            }
        }
        return sum;
    }
};