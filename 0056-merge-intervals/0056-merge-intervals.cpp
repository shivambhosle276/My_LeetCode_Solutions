#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            
            if (intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            }
          
            else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};