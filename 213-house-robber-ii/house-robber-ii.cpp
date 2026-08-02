class Solution {
public:
    int fun(vector<int>& nums, int i, int end_idx, vector<int>& dp) {
        if (i > end_idx)
            return 0;
        if (i >= end_idx) {
            return nums[i];
        }
        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(0 + fun(nums, i + 1, end_idx, dp),
                           nums[i] + fun(nums, i + 2, end_idx, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();    

        if (n == 1)
            return nums[0];

        vector<int> dp1(n + 5, -1);
        int ans1 = fun(nums, 0, n - 2, dp1);
        vector<int> dp2(n + 5, -1);  
        int ans2 = fun(nums, 1, n - 1, dp2);

        return max(ans1, ans2);
    }
};