class Solution {
public:
    bool validDigit(int n, int x) 
    {
        int cnt = 0;
        int lastd;
        while(n>0)
        {
            int d = n % 10;
            if(d==x) 
            {
                cnt ++;
            }
            
            lastd = d;
            n = n / 10;
        }
        if(lastd == x) return false;
        if(cnt > 0) return true;
        return false;
    }

};