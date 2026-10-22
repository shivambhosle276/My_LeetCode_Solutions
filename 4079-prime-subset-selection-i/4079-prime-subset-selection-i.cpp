class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int>prime;
        findPrime(n, prime);
        int sum = 0;
        vector<int>ans;
        for(auto i:prime){
            if(sum + i <= s) ans.push_back(i);
            else break;
            sum += i;
        }
        return ans;
    }
    void findPrime(int n, vector<int>&prime){
        vector<int>isPrime(n + 1, true);
        for(int i = 2;i*i <= n; i++){
            if(isPrime[i]){
                for(int j=i*i ;j<=n ;j+=i) isPrime[j]=false;
            }
        }
        for(int i = 2; i<=n; i++){
            if(isPrime[i]) prime.push_back(i);
        }
    }
};