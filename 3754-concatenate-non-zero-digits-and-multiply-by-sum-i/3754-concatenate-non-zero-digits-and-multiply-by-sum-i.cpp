class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        int sum=0;
        if(n==0)return 0;
        while(n>0)
        {
            int r = n%10;
            n=n/10;
            if(r!=0)
            {   
                sum+=r;
                s.push_back('0'+r);
            }
        }
        reverse(s.begin(), s.end());
        long long x = stoll(s);
        long long ans= sum*x;
        return ans;

        
    }
};