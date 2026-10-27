class Solution {
public:
    string binary(int n) {
        if (n == 0) return "0";

        string ans = "";

        while (n > 0) {
            ans += to_string(n % 2);
            n = n / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    int calculateScore(int a, int b) {
        string k1 = binary(a);
        string k2 = binary(b);

        int c1 = 0;
        int c2 = 0;

        for (int i = 0; i < k1.size(); i++) {
            if (k1[i] == '1') c1++;
        }

        for (int i = 0; i < k2.size(); i++) {
            if (k2[i] == '1') c2++;
        }

        int ans = 0;

        if (c1 >= c2)
            ans = c1 * c2;
        else
            ans = c2 / c1;

        return ans;
    }
};