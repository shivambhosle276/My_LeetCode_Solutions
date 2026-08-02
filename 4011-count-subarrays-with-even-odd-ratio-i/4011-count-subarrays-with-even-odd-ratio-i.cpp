class Solution {
public:
    int countRatioSubarrays(vector<int>& A, int a, int b) {
        // x/y<=a/b = x*b<=y*a
        int n=A.size(),res=0;
        for(int i=0;i<n;++i){
            int x=0,y=0;
            for(int j=i;j<n;++j){
                if(A[j]&1)
                    ++y;
                else
                    ++x;
                if(1L*x*b<=1L*y*a)
                    ++res;
            }
        }
        return res;
    }
};