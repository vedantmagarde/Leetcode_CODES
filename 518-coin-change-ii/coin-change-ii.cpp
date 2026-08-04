class Solution {
public:
    int fun(int amt, vector<int>& coins, int idx, vector<vector<int>>& dp) {
        if (amt == 0)
            return 1;

        if (amt < 0 || idx >= coins.size())
            return 0;

        if (dp[amt][idx] != -4)
            return dp[amt][idx];

        int skip = fun(amt, coins, idx + 1,dp);

        int take = 0;
        if (amt - coins[idx] >= 0)
            take = fun(amt - coins[idx], coins, idx,dp);
        return dp[amt][idx] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(5005, vector<int>(305, -4));
        return fun(amount, coins, 0,dp);
    }
};