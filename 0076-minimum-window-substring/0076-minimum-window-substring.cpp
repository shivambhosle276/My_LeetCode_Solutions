class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        // Store frequency of characters in t
        for (char c : t)
            mp[c]++;

        int left = 0, right = 0;
        int count = t.size();          // characters still needed

        int start = 0;
        int minLen = INT_MAX;

        while (right < s.size()) {

            // Include s[right] in the window
            if (mp.find(s[right]) != mp.end()) {
                mp[s[right]]--;

                if (mp[s[right]] >= 0)
                    count--;
            }

            // If all characters are found
            while (count == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove s[left] from the window
                if (mp.find(s[left]) != mp.end()) {
                    mp[s[left]]++;

                    if (mp[s[left]] > 0)
                        count++;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};