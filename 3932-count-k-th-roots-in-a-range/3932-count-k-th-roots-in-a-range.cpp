class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        double epsilon=1e-5;
        int L=ceil(pow(l, 1.0/k)), R=pow(r+epsilon, 1.0/k);
        return R-L+1;
    }
};