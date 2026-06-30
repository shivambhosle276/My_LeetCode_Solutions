class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA=0;
        int n = heights.size();
        int nse=0;
        int pse=0;
        int element=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {   
                element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxA=max(heights[element]*(nse-pse-1),maxA);
                
            }
            st.push(i);
        }
        while(!st.empty())
        {
             nse=n;
             element=st.top();
             st.pop();
             pse=st.empty()?-1:st.top();
             maxA=max(heights[element]*(nse-pse-1),maxA);
        }
        return maxA;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;
        int maxi=0;
        int rows=matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        for(int i=0;i<rows;i++)
        {   
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]++;
                }
                else heights[j]=0;
            }
           maxi=max(largestRectangleArea(heights),maxi);
        }
        return maxi;
    }

};