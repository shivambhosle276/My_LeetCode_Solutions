class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
        map<int,int> mp;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            mp[bulbs[i]]++;
        }

          for(auto it : mp)
        {
            if(it.second % 2 != 0)
            {
                result.push_back(it.first);
            }
        }
        sort(result.begin(),result.end());
        return result;
        
    }
};