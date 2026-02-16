class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int jump=nums[0];
        if(jump==0){
            return false;
        }
        for(int i=1;i<n-1;i++){
            // if(i==n-1)
            int j1=nums[i];
            jump--;
            jump=max(jump,j1);
            if(jump==0){
                return false;
            }
        }
        return true;
    }
};