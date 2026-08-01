class Solution {
public:
    int minCoins(int amount, vector<int>& coins, vector<int>& dp) {
        // Base Case
        if (amount == 0)
            return 0;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] == amount)
                return 1;
    
        }
        if (dp[amount] != -1)
            return dp[amount];
        int result = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] > 0)
                result = min(result, minCoins(amount - coins[i], coins, dp));
        }
        // if (result == INT_MAX)
        //     return dp[amount] = INT_MAX; // Update hi nhi hua
        // saare coins amount se bde h
        // return dp[amount] = 1 + result;  //Noraml case
        return dp[amount] = (result == INT_MAX) ? INT_MAX : 1 + result;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, -1);
        int ans = minCoins(amount, coins, dp);
        return ((ans == INT_MAX) ? -1 : ans);
    }
};