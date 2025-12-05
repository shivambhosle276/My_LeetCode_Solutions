class Solution {
public:
    int minimumChairs(string s) {
        
        int c=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++)
        {   
        
            if(s[i]=='E')
            {
                c++;
            }
            else if(s[i]=='L')
            {
                c--;
            } 
            maxi=max(maxi,c);

        }
        return maxi;
    }
};