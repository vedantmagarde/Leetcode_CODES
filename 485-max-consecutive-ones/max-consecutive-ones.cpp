class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0, count = 0;
        while (i < nums.size()) {
            count = nums[i] == 1 ? count + 1 : 0;
            ans = max(ans, count);
            i++;
        }
        return ans;
    }
};