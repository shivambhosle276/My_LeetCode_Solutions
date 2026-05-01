class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();

        unordered_map<char,int> mp;        // frequency
        unordered_map<char,int> firstPos;  // first occurrence
        vector<char> ans;

        // count + first occurrence
        for (int i = 0; i < n; i++) {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                mp[s[i]]++;
                if (firstPos.find(s[i]) == firstPos.end()) {
                    firstPos[s[i]] = i;
                }
            }
        }

        // move to vector
        vector<pair<char,int>> vec(mp.begin(), mp.end());

        // sort: freq desc, first occurrence asc
        sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
            if (a.second == b.second)
                return firstPos[a.first] < firstPos[b.first];
            return a.second > b.second;
        });

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {

                while (j < vec.size() && vec[j].second == 0) {
                    j++;
                }

                if (j < vec.size()) {
                    ans.push_back(vec[j].first);
                    vec[j].second--;
                }

            } else {
                ans.push_back(s[i]);
            }
        }

        return string(ans.begin(), ans.end());
    }
};