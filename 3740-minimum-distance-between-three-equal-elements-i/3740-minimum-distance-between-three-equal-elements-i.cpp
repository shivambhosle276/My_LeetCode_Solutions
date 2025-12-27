class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int i=0; i<n; ++i){
            int j = i+1;
            while(j<n && nums[j] != nums[i]){
                j++;
            }
            int k = j+1;
            while(k<n && nums[k] != nums[i]){
                k++;
            }
            if(j<n && k<n && nums[i] == nums[j] && nums[j] == nums[k]){
                int x = abs(i-j) + abs(j-k) + abs(k-i);
                ans = min(ans, x);        
            }
        }        
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};