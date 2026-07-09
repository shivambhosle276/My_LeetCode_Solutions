class Solution {
public:
    vector<string> ans;

    void dfs(int idx, int n, int k, int cost,bool prevOne, string& cur) {

        if (cost > k) return;

        if (idx == n) {
            ans.push_back(cur);
            return;
        }

        cur.push_back('0');
        dfs(idx + 1, n, k, cost, false, cur);
        cur.pop_back();

        if (!prevOne) { // if prev char is not 1 then we can put 1
            cur.push_back('1');
            dfs(idx + 1, n, k, cost + idx, true, cur);
            cur.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        string cur;
        dfs(0, n, k, 0, false, cur);
        return ans;
    }
};