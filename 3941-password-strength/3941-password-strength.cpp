class Solution {
public:
    int passwordStrength(string password) {
        int n=password.size();
        int s=0;
        unordered_map<int,int> mp;
        for(char c:password)
        {   
            mp[c]++;
            if(mp[c]>1)continue;
            if(c>='a' && c<='z')s++;
            else if(c>='A' && c<='Z')s+=2;
            else if(c>='0'&& c<='9')s+=3;
            else s+=5;
        }
        return s;
    }
};