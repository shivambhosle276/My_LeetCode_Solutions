class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
         int n = nums.size();

        if (n % k != 0) return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
            pq.push(x);
        }

        while (!pq.empty()) {
            int start = pq.top();
            pq.pop();

          
            if (mp[start] == 0) continue;

         
            for (int i = 0; i < k; i++) {
                int curr = start + i;

                if (mp[curr] == 0)
                    return false;

                mp[curr]--;
            }
        }

        return true;
        
    }
};