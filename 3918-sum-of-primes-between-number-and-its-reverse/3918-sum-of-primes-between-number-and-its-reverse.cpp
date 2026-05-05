class Solution {
public:
bool isPrime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0)
            return false;
    }
    return true;
    }
    int reverseNumber(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
    }
    int sumOfPrimesInRange(int n) {
        int m=reverseNumber(n);
        int maxi=max(n,m);
        int mini=min(n,m);
        int sum=0;
        for(int i=mini;i<=maxi;i++)
        {
            if(isPrime(i))sum+=i;
        }
        return sum;
    }
};