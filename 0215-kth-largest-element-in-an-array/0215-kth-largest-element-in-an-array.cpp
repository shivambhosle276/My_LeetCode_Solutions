class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=1;i<=k;i++)
        {
             ans=pq.top();
              pq.pop();
        }
        return ans;
    }
};