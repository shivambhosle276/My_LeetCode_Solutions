class Solution {
public:
    int solve(int ind , vector<int> &days , vector<int> &costs,vector<int> &dp)
    {   
        int d=days.size();
        int save1=d;
        int save2=d;
       if(ind>=d)return 0;
       if(dp[ind]!=-1)return dp[ind];

       int take1=costs[0]+solve(ind+1,days,costs,dp);
        for(int i=ind;i<=d-1;i++)
        {   
            if(days[i]>=days[ind]+7)
            {
                save1=i;
                break;
            }

        }
        int take7=costs[1]+solve(save1,days,costs,dp);
        for(int i=ind;i<=d-1;i++)
        {   
            if(days[i]>=days[ind]+30)
            {
                save2=i;
                break;
            }

        }
       int take30=costs[2]+solve(save2,days,costs,dp);

        return dp[ind]=min(take1,min(take7,take30));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d=days.size();
        vector<int> dp(d+1,-1);
       return solve(0,days,costs,dp);
        
    }
};