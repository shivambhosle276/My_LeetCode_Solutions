class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) { 
        int n = capacity.size();
        int mini =INT_MAX;
        int index=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(capacity[i]>=itemSize)
            {
                cnt++;
            }
        }
        if(cnt==0)return -1;
        for(int i=0;i<n;i++)
        {
            if(capacity[i]>=itemSize && capacity[i]<mini)
            {
                mini=capacity[i];
                index=i;
            }
        }
        return index;
        
    }
};