class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int itr = 0;
        while (itr < s.length()) {

            if (!st.empty() && st.top() == '(' && s[itr] == ')') {
                st.pop();
            } else {
                st.push(s[itr]);
            }
            itr++;
        }

        itr++;
        return st.size();
    }
};