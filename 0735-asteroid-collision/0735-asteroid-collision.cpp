class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n= a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {
               st.push(a[i]);
            }
            else{
                 while(!st.empty() && st.top()>0 && st.top()<-a[i])
                 {
                    st.pop();
                 }
                   if(st.empty() || st.top()<0)
                 {
                    st.push(a[i]);
                 }
                 if(!st.empty()&& st.top()==-a[i])
                 {
                    st.pop();
                 }
            }
        }
        vector<int> v(st.size());
        int i=st.size()-1;
        while(!st.empty())
        {
            v[i--]=st.top();
            st.pop();
        }
        return v;
    }
};