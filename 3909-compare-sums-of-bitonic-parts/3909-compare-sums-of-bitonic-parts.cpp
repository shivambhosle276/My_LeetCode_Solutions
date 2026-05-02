class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n-1 && nums[i] < nums[i+1]) {
            i++;
        }

        int peak = i;

        long long  sum1 = 0, sum2 = 0;

      
        for(int j = 0; j <= peak; j++) {
            sum1 += nums[j];
        }

       
        for(int j = peak; j < n; j++) {
            sum2 += nums[j];
        }

        if(sum1 > sum2) return 0;
        else if(sum2 > sum1) return 1;
        else return -1;
    }
};