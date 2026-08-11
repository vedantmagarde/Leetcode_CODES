class Solution {
public:
    bool fun(vector<int>& nums, int total, int i, vector<vector<int>>& dp) {
        if (i >= nums.size())
            return false;

        if (total == 0)
            return true;
        if (total < 0)
            return false;

        if (dp[i][total] != -1)
            return dp[i][total];
        bool take = fun(nums, total - nums[i], i + 1, dp);
        bool skip = fun(nums, total, i + 1, dp);

        return dp[i][total] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto x : nums) {
            total += x;
        }
        if (total % 2 != 0)
            return false;
        total /= 2;
        vector<vector<int>> dp(nums.size() + 5, vector<int>(total + 5, -1));
        return fun(nums, total, 0, dp);
    }
};