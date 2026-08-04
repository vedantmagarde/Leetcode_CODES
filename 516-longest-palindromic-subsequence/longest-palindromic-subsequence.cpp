class Solution {
public:
    int fun(string& s, int i1, int i2, vector<vector<int>>& dp) {
        if (i1 >= s.length() || i2 < 0)
            return 0;

        if (dp[i1][i2] != -4)
            return dp[i1][i2];

        if (s[i1] == s[i2])
            return dp[i1][i2] = 1 + fun(s, i1 + 1, i2 - 1, dp);

        int ans1 = fun(s, i1 + 1, i2, dp);
        int ans2 = fun(s, i1, i2 - 1, dp);

        return dp[i1][i2] = max(ans1, ans2);
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(1005, vector<int>(1005, -4));
        return fun(s, 0, s.length() - 1, dp);
    }
};