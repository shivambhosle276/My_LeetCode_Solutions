class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int z = count(begin(nums), end(nums), 0);
        return count(begin(nums), end(nums) - z, 0);
    }
};