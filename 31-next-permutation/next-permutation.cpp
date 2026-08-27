class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int itr = nums.size() - 2;
        for (; itr >= 0; itr--) {
            if (nums[itr] < nums[itr + 1]) {
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0 && itr >= 0; i--) {
            if (nums[i] > nums[itr]) {
                swap(nums[i], nums[itr]);
                break;
            }
        }
        reverse(nums.begin() + itr + 1, nums.end());
    }
};