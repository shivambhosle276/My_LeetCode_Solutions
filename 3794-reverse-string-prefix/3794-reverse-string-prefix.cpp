class Solution {
public:
    string reversePrefix(string s, int k) {
        int n=s.size();
        string save;
        for(int i=0;i<k;i++)
        {
            save.push_back(s[i]);
        }
        reverse(save.begin(),save.end());
        for(int i=k;i<n;i++)
        {
            save.push_back(s[i]);
        }
        return save;
    }
};