class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if (1LL * m * k > n) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int c = 0, bouquets = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    c++;

                    if (c == k) {
                        bouquets++;
                        c = 0;
                    }
                } else {
                    c = 0;
                }

                if (bouquets >= m) break;
            }

            if (bouquets >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};