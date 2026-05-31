class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mp;
        set<int> s;
        int sum = 0;

        while (n > 0) {
            int r = n % 10;
            s.insert(r);
            mp[r]++;
            n /= 10;
        }

        while (!s.empty()) {
            int k = *s.begin();
            s.erase(s.begin());

            sum += k * mp[k];
        }

        return sum;
    }
};