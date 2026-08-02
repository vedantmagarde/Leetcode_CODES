class Solution {
public:
    int fun(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;

        if (amount < 0 || idx >= coins.size())
            return 0;

        if (dp[amount][idx] != -5)
            return dp[amount][idx];
            
        int skip = fun(amount, coins, idx + 1, dp);

        int take = 0;
        if (amount >= coins[idx]) {
            take = fun(amount - coins[idx], coins, idx, dp);
        }
        return dp[amount][idx] = skip + take;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(5005, vector<int>(305, -5));
        return fun(amount, coins, 0, dp);
    }
};