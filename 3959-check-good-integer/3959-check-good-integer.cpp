class Solution {
public:
    bool checkGoodInteger(int n) {
        vector<int> v;
        
        while(n>0)
        {
            int r=n%10;
            v.push_back(r);
            n=n/10;
        }
        int sum1=0;
        int sum2=0;
       for(int i=0;i<v.size();i++)
       {
         sum1+=v[i];
         sum2+=(v[i]*v[i]);
       }
       if(sum2-sum1>=50)return true;
       return false;
        
    }
};