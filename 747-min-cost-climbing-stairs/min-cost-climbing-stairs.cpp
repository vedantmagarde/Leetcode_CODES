class Solution {
public:
    int fun(vector<int>& cost, int step, vector<int>& dp) {
        if (step > cost.size())
            return 0;
        if (step >= cost.size() - 2)
            return cost[step];

        if (dp[step] != -1)
            return dp[step];
        return dp[step] = cost[step] +
                          min(fun(cost, step + 1, dp), fun(cost, step + 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 5, -1);
        return min(fun(cost, 0, dp), fun(cost, 1, dp));
    }
};