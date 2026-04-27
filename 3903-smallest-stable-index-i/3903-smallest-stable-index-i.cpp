class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

      
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

      
        int prefMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            prefMax = max(prefMax, nums[i]);

            int instability = prefMax - suffMin[i];
            if (instability <= k) return i;
        }

        return -1;
    }
};