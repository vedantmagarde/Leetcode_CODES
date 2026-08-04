class Solution {
public:
    int fun(string& text1, string& text2, int i1, int i2,
            vector<vector<int>>& dp) {
        if (i1 >= text1.length() || i2 >= text2.length())
            return 0;

        if (dp[i1][i2] != -4)
            return dp[i1][i2];

        if (text1[i1] == text2[i2])
            return 1 + fun(text1, text2, i1 + 1, i2 + 1, dp);

        int ans1 = fun(text1, text2, i1 + 1, i2, dp);
        int ans2 = fun(text1, text2, i1, i2 + 1, dp);

        return dp[i1][i2] = max(ans1, ans2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(1005, vector<int>(1005, -4));
        return fun(text1, text2, 0, 0, dp);
    }
};