class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        stack<string> st;
        int ind = 0;
        while (ind < size) {
            while (ind < size && path[ind] == '/')
                ind++;
            string temp = "";
            while (ind < size && path[ind] != '/') {
                temp += path[ind];
                ind++;
            }
            if (temp.empty() || temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(temp);
            }
            
        }
        vector<string> v;

        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());

        string ans = "";

        for (string s : v) {
            ans += "/";
            ans += s;
        }

        if (ans == "")
            return "/";

        return ans;
    }
};