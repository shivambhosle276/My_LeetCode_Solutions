class Solution {
public:
    bool possible(vector<int>& bloomDay,int day,int m,int k)
    {   int cnt=0;
        int   boq=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(day>=bloomDay[i])cnt++;
            else {
                boq+=(cnt/k);
                cnt=0;
            }
        }
        boq+=(cnt/k);
        if(boq>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int ans=0;
        if ((long long)bloomDay.size() < (long long)m * k) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());;
        while(low<=high)
        {   
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;

        
    }
};