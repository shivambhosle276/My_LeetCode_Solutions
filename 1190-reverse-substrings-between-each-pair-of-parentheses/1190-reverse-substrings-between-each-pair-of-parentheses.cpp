class Solution {
public:
    string reverseParentheses(string s) {

        int c = 0;

        for (char ch : s) {
            if (ch == '(') c++;
        }

        while (c > 0) {

            int open = -1, close = -1;
            int n = s.size();

        
            for (int i = 0; i < n; i++) {
                if (s[i] == '(')
                    open = i;
            }

            for (int i = open + 1; i < n; i++) {
                if (s[i] == ')') {
                    close = i;
                    break;
                }
            }

            reverse(s.begin() + open + 1, s.begin() + close);

            s.erase(s.begin() + close);
            s.erase(s.begin() + open);

            c--;
        }

        return s;
    }
};