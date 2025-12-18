class Solution {
public:
    string greatestLetter(string s) {
        vector<int> freqLowerCase(26, 0);
        vector<int> freqUpperCase(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                freqUpperCase[s[i] - 'A'] = 1;
            else if (s[i] >= 'a' && s[i] <= 'z')
                freqLowerCase[s[i] - 'a'] = 1;
        }
        for (int i = 25; i >= 0; i--) {
            if (freqLowerCase[i] == 1 && freqUpperCase[i] == 1)
                return string(1, 'A' + i);
        }
        return "";
    }
};