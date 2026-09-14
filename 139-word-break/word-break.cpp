class Solution {
public:
    bool fun(string s, unordered_set<string>& st, int start, vector<int>& dp) {
        if (start == s.length())
            return true;

        if (dp[start] != -1)
            return dp[start];
        for (int i = start; i < s.length(); i++) {

            if (st.find(s.substr(start, i - start + 1)) != st.end() &&
                fun(s, st, i + 1, dp)) {
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 5, -1);
        return fun(s, st, 0, dp);
    }
};