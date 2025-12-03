class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,bool> map;
        for(int x:nums)
        {
            map[x]=true;
        }
        bool ans = true;
        int i=1;
        int sol=0;
        while(ans==true)
        {   
            if(map.find(k*i)==map.end())
            {
                ans=false;
                sol=k*i;
            }
            i++;
        }
        return sol;
        
    }
};