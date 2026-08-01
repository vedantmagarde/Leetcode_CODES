class Solution {
public:
    int robRE(vector<int>& nums, int i, vector<int>& dp) {

        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];

        int robAmount1 = 0 + robRE(nums, i + 1, dp);       // skipped
        int robAmount2 = nums[i] + robRE(nums, i + 2, dp); // looted

        return dp[i] = max(robAmount1, robAmount2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robRE(nums, 0, dp);
    }
};