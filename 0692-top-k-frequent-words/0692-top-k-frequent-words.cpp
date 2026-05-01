class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        int n= words.size();
         unordered_map<string, int> freq;
         for(int i=0;i<n;i++)
         {
            freq[words[i]]++;
         }
         vector<pair<string,int>> v(freq.begin(),freq.end());
         sort(v.begin(), v.end(), [](auto &a, auto &b) {
                 if (a.second == b.second)
                 return a.first < b.first;   
                 return a.second > b.second;
        });
         for(int i=0;i<k;i++)
         {
            res.push_back(v[i].first);
         }
         return res;


    }
};