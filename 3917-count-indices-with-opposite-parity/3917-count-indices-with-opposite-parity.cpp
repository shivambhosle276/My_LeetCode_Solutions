class Solution {
public:
    bool solve(int ind)
    {
        if(ind%2==0)return true;
        else return false;
    }
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int even=0;
        int odd=0;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {  
           
           if(solve(nums[i]))
           { 
            ans.push_back(odd);
             even++;
           }
           else 
           { 
            ans.push_back(even);
            odd++;
           }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};