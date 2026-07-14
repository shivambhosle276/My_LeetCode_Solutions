class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int lb = 0;
        int ub = 0;
        vector<string> ranges;

        for (int i = lb; i < nums.size(); i++) {
            if (i == nums.size() - 1 || (nums[i] + 1 != nums[i + 1])) {
                ub = i;

                if (lb != ub) {
                    string s = to_string(nums[lb]) + "->" + to_string(nums[ub]);
                    ranges.push_back(s);
                } else {
                    ranges.push_back(to_string(nums[lb]));
                }

                lb = i + 1;
            }
        }

        return ranges;
    }
};