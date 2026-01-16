class Solution {
public:
    // total water is trapped into the bars
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int lmax = INT_MIN, rmax = INT_MIN;
        int ans = 0;

        while (l < r) {
            lmax = max(lmax, h[l]);
            rmax = max(rmax, h[r]);

           if (lmax < rmax) {
                   ans += lmax - h[l];
                    l++;
               } else {
                       ans += rmax - h[r];
                       r--;
}

        }
        return ans;
    }
};
