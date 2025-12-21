class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i%2==0 && nums[i]==nums[i+1])
            {
                nums.erase(nums.begin()+1);
                count++;
                i--;
            }
        }
        if(nums.size()%2!=0)count++;
        return count;

    }
};