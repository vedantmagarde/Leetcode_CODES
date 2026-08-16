class Solution {
public:
    int mod = 1000000007;
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<int> pre_(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pre_[i] = (pre_[i - 1] * 2) % mod;
        }
        int l = 0;
        int r = nums.size() - 1;
        int count = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                // int temp = fun(2, r - l) % mod;
                count = (count + pre_[r-l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return count;
    }
};