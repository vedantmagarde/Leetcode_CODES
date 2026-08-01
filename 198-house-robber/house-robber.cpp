class Solution {
public:
    int fun(vector<int>& cost, int step, vector<int>& dp) {
        if (step >= cost.size())
            return 0;
            
        if (dp[step] != -1)
            return dp[step];
        return dp[step] = max(fun(cost, step + 1, dp),
                              cost[step] + fun(cost, step + 2, dp));
    }
    int rob(vector<int>& cost) {
        vector<int> dp(cost.size() + 5, -1);
        return max(fun(cost, 0, dp), fun(cost, 1, dp));
    }
};