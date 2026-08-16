class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        int len = 1;
        for (int i = 0; i + 1 < nums.size(); i++) {

            if (nums[i + 1] == nums[i])
                continue;
            if (nums[i + 1] - nums[i] == 1) {
                len++;
                ans = max(len, ans);
            } else {
                len = 1;
            }
            // cout << len << " " << ans << endl;
        }
        ans = max(len, ans);
        return ans;
    }
};